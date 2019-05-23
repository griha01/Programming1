#include <stdio.h>
#include <math.h>
#define eps 0.000000001
typedef double (*func)(double x, double c, double d); // задаем тип func
double fx(double, double, double);      // прототип вычисляемой функции
double fx(double x, double d, double c) // вычисляемая функция
{
  return pow(x, 4) + c * pow(x, 3) - d * x;
}
////////////////////////////////////////////////////////////////////

double decision(func fx, double x1, double x2, double c, double d)
{
  double v;
  int i;
  while (fabs(x1 - x2) > eps) // пока не достигнута точность eps(0.0000001)
  {
    v = (x1 * fx(x2, c, d) - x2 * fx(x1, c, d)) / (fx(x2, c, d) - fx(x1, c, d));
    x1 = x2;
    x2 = v;
  }
  return x1;
}

///////////////////////////////////////////////////////////////////

int main()
{
  double c = 5, d = 2;
  double x1 = -2, x2 = 1; //х1, х2 - начало и конец отрезка, для которого применяем метод секущих

  printf("Интервал:[%.2lf,%.2lf] \n", x1, x2); // Вывод в консоль интервала
  printf("Ответ:%.9f\n", decision(fx, x1, x2, d, c)); // Вывод в консоль ответа
  return 0;
}
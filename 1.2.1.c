#include <stdio.h>
#include <math.h>
#define eps 0.0000001
typedef double (*func)(double x, double c, double d); // задаем тип func
//Объявим прототипы функций
double decision(func,func,double,double,double); // прототип нахождения корня функции
double fx(double, double, double); // прототип вычисляемой функции
double dfx(double, double, double); // прототип производной функции

double fx(double x, double c, double d) // вычисляемая функция
{
  return pow(x,5)+c*pow(x,2)-d;
}

double dfx(double x, double c, double d) // производная функции
{
  return 5*pow(x,4)+c*2*x;
}

///////////////////////////////////////////////////////////////////

double decision(func fx, func dfx, double x0, double c, double d)
{
  double x1;
  x1 = x0 - fx(x0, c, d) / dfx(x0, c, d); // первое приближение
  while (fabs(x1 - x0) > eps)             // пока не достигнута точность eps(0.0000001)
  {
    x0 = x1;
    x1 = x1 - fx(x1, c, d) / dfx(x1, c, d); // последующие приближения
  }
  return x1;
}
///////////////////////////////////////////////////////////////////

int main()
{
  printf("Ответ : %lf\n", decision(fx, dfx, 1, 2, 1)); // Вывод в консоль ответа
  return 0;
}


#include <stdio.h>
#include <math.h>
#define e 2.7182818284590452
#define PI 3.1415926535897932384
double Ramanujan(int, int);
double Ramanujan(int countS, int countD)
{
  int i;
  double s = 0, a = 1, s1 = 0;
  int n = 1;
  unsigned long int b = 1;
  for (i = countS; i > 0; i--)
  {
    a = 1 / (long double)b;
    n += 2;
    b *= n;
    s += a;
  }
  
  for (i = countD; i > 0; i--, countD--)
  {
    s1 = 1 / (1 + countD * s1);
  }
  printf("%lf\n", s);
  printf("%lf\n", s1);
  return s + s1;
}
int main()
{
  int countS, countD;
  printf("Введите колличество членов ряда\n");
  scanf("%d", &countS);
  printf("Введите колличество членов цепной дроби\n");
  scanf("%d", &countD);
  printf("Ответ :   %.4lf \n", Ramanujan(countS, countD));
  return 0;
}
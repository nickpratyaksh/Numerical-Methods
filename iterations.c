#include <stdio.h>

double func(double x);
double diffFunc(double x);
void findRoot(double a, double b);
double bisection(double a, double b, int n);
double regularFalse(double a, double b, int n);
double newtonRaphson(double x, int n);

double func(double x)
{
    return x * x * x - x * x + 2;
}

double diffFunc(double x){
    return 3 * x * x - 2 * x;
}

int main()
{
    printf("%lf", newtonRaphson(-2, 10));
    // findRoot(-2, 0);
    return 0;
}

void findRoot(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        printf("Given values do not bracket the root! \nf(a) = %lf, f(b) = %lf", func(a), func(b));
        return;
    }
    else
        printf("Root = %lf", regularFalse(-2, 0, 16));
}

double bisection(double a, double b, int n)
{
    int i = 1;
    double mid;
    while (i <= n)
    {
        mid = (a + b) / 2;
        double c = func(mid);
        // printf("%lf\n", c);
        if (c < 0)
            a = mid;
        else
            b = mid;
        i++;
    }
    return mid;
}

double regularFalse(double a, double b, int n)
{
    int i = 1;
    double c;
    while (i <= n)
    {
        double aOut = func(a);
        double bOut = func(b);
        c = ((a * bOut) - (b * aOut)) / (func(b) - func(a));
        double output = func(c);
        // printf("%lf\n", output);
        if (output < 0)
            a = c;
        else
            b = c;
        i++;
    }
    return c;
}

double newtonRaphson(double x, int n){
    for (int i = 0; i < n; i++)
        x -= func(x)/diffFunc(x);
    return x;
}
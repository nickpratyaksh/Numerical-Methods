#include <stdio.h> // till 3 correct decimal places

void gaussElimination();
void gaussJordan();

int main()
{
    gaussJordan();
    return 0;
}

void gaussElimination()
{
    int i, j, k, x, y, n;
    float sum, ratio;
    printf("Enter no of Unknowns\n");
    scanf("%d", &n);
    float a[n][n + 1], value[n];
    printf("Enter the Augmented Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);
    }
    // Converts the Augmented matrix to Upper Triangular Matrix form

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j > i)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++)
                    a[j][k] = a[j][k] - (ratio * a[i][k]);
            }
        }
    }

    // Performs Back Substitution to find values of Unknowns
    value[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
            sum = sum + a[i][j] * value[j];
        value[i] = (a[i][n] - sum) / a[i][i];
    }
    // prints the Value of Unknowns
    printf("Values of unknowns are:\n");
    for (i = 0; i < n; i++)
        printf("Value[%d]=%f\n", i, value[i]);
}

void gaussJordan()
{
    int i, j, k, n;
    float ratio;
    printf("Enter no of Unknowns\n");
    scanf("%d", &n);
    float a[n][n + 1];
    printf("Enter the Augmented Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);
    }
    // Converts the Augmented matrix to Diagonal form
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++)
                    a[j][k] = a[j][k] - (ratio * a[i][k]);
            }
        }
    }
    // prints the Value of Unknowns
    printf("Values of unknowns are:\n");
    for (i = 0; i < n; i++)
        printf("Value of Variable %d = %f\n", i, a[i][n] / a[i][i]);
}

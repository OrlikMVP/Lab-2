#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    double x, leftX = 0, rightX = M_PI/2;

    printf("Enter x, N: ");
    if (scanf("%lf %d", &x, &N) != 2) {
        printf("Invalid input\n");
        return -1;
    }

    if (x < leftX || x > rightX) {
        char* fmt = "Incorrect %.4f. Need from [%.4f, %.4f]\n";
        printf(fmt, x, leftX, rightX);
        return -1;
    }

    double a = 1, S = 0;

    for (int n = 1; n <= N; ++n) {
        //double q = (pow(cos(x),2.0)*n)/(n+1);
        double q = (pow(cos(x),2.0*(n+1))*n)/((n+1)*pow(cos(x),2.0*n));
        S += a;
        a *= q;

    }

    S = S*(-1);

    printf("S=%.7f\n", S);
    double y = 2*log(sin(x));
    printf("y=%.7f\n", y);
    double eps = fabs(S-y)/fabs(S)*100;
    printf("e=%.2f%%\n", eps);

    return 0;
}

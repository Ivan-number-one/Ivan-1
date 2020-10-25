#include <stdio.h>
#include <math.h>
#include <TXLib.h>

void test_input (double* a, double* b, double* c);
int decision(double a, double b, double c, double* x1, double* x2);
void print_result(double* x1, double* x2, int* marker);
const double EPSILON = 1E-6;
void Solve_Square_Test();


int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf ("# Square equation solver\n"
            "# (c) Banana_nigga, 2020\n\n");

    printf ("Equation of the form  a*x^2 + b*x + c = 0\n\n");

Solve_Square_Test();
test_input(&a, &b, &c);
int marker = decision(a, b, c, &x1, &x2);
print_result(&x1, &x2, &marker);

}


//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------


void test_input (double* a, double* b, double* c)
{
    while (true)
    {
        printf ("Enter a, b and c\n");
        int check_type = scanf("%lg %lg %lg", a, b, c);

        if (check_type == 3) break;
        else
            {
             scanf("%*s");
             printf ("Wrong type of input. Please, try again\n");
            }
    }

}


//-----------------------------------------------------------------------------


int decision(double a, double b, double c, double* x1, double* x2)
{
     double discr = (b)*(b) - 4*(a)*(c);
     if ((fabs(a) < EPSILON) && (fabs(b) > EPSILON))
         {
          *x1 = -c/(b) + 0;
           return 1;// 1 root and a = 0
         }

     else
         {
          if ((discr < - EPSILON) || ((fabs(a) < EPSILON) && (fabs(b) < EPSILON) && (fabs(c) > EPSILON))) return 2;// no roots, discr < 0 or a,b,c = 0
          if ((fabs(a) < EPSILON) && (fabs(b) < EPSILON) && (fabs(c) < EPSILON))                          return 3;// infinity roots, a,b,c = 0
         }


     if (discr > EPSILON)
         {
          *x1 = (-b + sqrt(discr))/(2*a);
          *x2 = (-b - sqrt(discr))/(2*a);
           return 4; // 2 roots
         }

     if (fabs(discr) < EPSILON)
         {
          *x1 = -b/(2*a);
           return 5; // 1 root, discr = 0
         }

return -1;
}


//-----------------------------------------------------------------------------

void print_result(double* x1, double* x2, int* marker)
{
    if (*marker ==  1) printf("x1 = x2 = %lg\n", *x1);
    if (*marker ==  2) printf("No roots\n");
    if (*marker ==  3) printf("Infinity roots\n");
    if (*marker ==  4) printf("x1 = %lg, x2 = %lg\n", *x1, *x2);
    if (*marker ==  5) printf("x1 = x2 = %lg\n", *x1);
    if (*marker == -1) printf("System fail. Please, contact the developers\n");
}


//-----------------------------------------------------------------------------

void Solve_Square_Test()
{
 printf("/Solve_Square_Test/\n\n");

 double X1, X2 = 0;

 decision(5, 10, 5, &X1, &X2);
 if (X1 == -1 && X2 == 0)                                            printf ("Test 1 OK\n");
 else                                                                printf ("Test 1 BAD: X1 = -1 expected\n"
                                                                             "but X1 = %lg, X2 = %lg\n", X1, X2);
 decision(9, -3, -6, &X1, &X2);
 if ((X1 == 1) && (X2 < (-2)/3 + EPSILON))                           printf ("Test 2 OK\n");
 else                                                                printf ("Test 2 BAD: X1 = 1, X2 = -0.666667 expected\n"
                                                                            "but X1 = %lg, X2 = %lg\n", X1, X2);
 decision(1, -5, 6, &X1, &X2);
 if (X1 == 3 && X2 == 2)                                             printf ("Test 3 OK\n");
 else                                                                printf ("Test 3 BAD: X1 = 3, X2 = 2 expected\n"
                                                                            "but X1 = %lg, X2 = %lg\n", X1, X2);
 decision(0, 0, 0, &X1, &X2);
 if (X1 == 3 && X2 == 2)                                             printf ("Test 4 OK\n");
 else                                                                printf ("Test 4 BAD: Infinity roots expected\n"
                                                                             "but X1 = %lg, X2 = %lg\n", X1, X2);
 decision(0, 0, 5, &X1, &X2);
 if (X1 == 3 && X2 == 2)                                             printf ("Test 5 OK\n");
 else                                                                printf ("Test 5 BAD: No roots roots expected\n"
                                                                             "but X1 = %lg, X2 = %lg\n", X1, X2);
 decision(0, -9, -18, &X1, &X2);
 if (X1 == -2 && X2 == 2)                                            printf ("Test 6 OK\n");
 else                                                                printf ("Test 6 BAD: X1 = -2 expected\n"
                                                                             "but X1 = %lg, X2 = %lg\n", X1, X2);
 decision(4, 1, 6, &X1, &X2);
 if (X1 == -2 && X2 == 2)                                            printf ("Test 7 OK\n");
 else                                                                printf ("Test 7 BAD: No roots expected\n"
                                                                             "but X1 = %lg, X2 = %lg\n", X1, X2);
 decision(1, -4, 4, &X1, &X2);
 if (X1 == 2 && X2 == 2)                                             printf ("Test 8 OK\n\n");
 else                                                                printf ("Test 8 BAD: X1 = 2 expected\n"
                                                                             "but X1 = %lg, X2 = %lg\n", X1, X2);

}


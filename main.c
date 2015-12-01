#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
load() -> Takes in 3 decimal values and returns one decimal output
b2d() -> Takes in an array of integers representing a binary number, returns the decimal value
d2b() -> Takes in a decimal value and a pointer to an array of integers, updates the array with the binary value
-------------------------
Last updated: 15-May-2015
-------------------------
*/
int main()
{
    system("color 1f");
    printf("Decimal ALU.\n");
    printf("\nInput format: Operand Operator Operand.\n\n");
    int i;//Loop variable for binary output loop
    int a; //Variable A, where the first term is stored
    int b; //Variable B, where the second term is stored
    int operation; //Operation
    int result,binaryResult[4]; //Decimal and binary output variables
    scanf("%d %d %d",&a,&operation,&b); //Reads in 3 decimal values, operand 1,operator, operand 2
    result=load(a,operation,b); //Decimal output
    printf("\nOutput: %d\n",result );
    return 0;
}
int load(int a, int operation, int b)
{
    int i;
    int out1[8]; // Term 1 stored here if converted to binary
    int out2[8]; // Term 2 stored here if converted to binary
    int out3[8]; // Functions requiring binary conversion store the output here
    d2b(a,out1); // Converts the first term to binary
    d2b(b,out2); //Converts the second term to binary
    switch(operation) //Switch based on operation
    {
    case 0:  //Addition
        return add(a,b);
        break;

    case 1: //Subtraction (A-B)
        return subtract(a,b);
        break;
    case 2: //Subtraction (B-A)
        return subtract(b,a);
        break;
    case 3: //Multiplication
        return multiply(a,b);
        break;
    case 4: // A and B
        AndWise(out1,out2,out3);
        return b2d(out3);
        break;
    case 5: //A or B
        OrWise(out1,out2,out3);
        return b2d(out3);
        break;
    case 6: //A xor B
        XorWise(out1,out2,out3);
        return b2d(out3);
        break;
    case 7: //A nand B
        NandWise(out1,out2,out3);
        return b2d(out3);
        break;

    case 8://Twos complement of A
        onesComplement(out1,out3);
        return b2d(out3)+1;
        break;
    case 9: //Ones complement of A
        onesComplement(out1,out3);
        return b2d(out3);
        break;
    case 10: //Shift A - Left logical
        shiftLeftLogical(out1,out3);
        return b2d(out3);
        break;
    case 11: //Shift A - Right logical
        shiftRightLogical(out1,out3);
        return b2d(out3);
        break;
    case 12: //Shift A - Left arithmetic
        shiftLeftArithmetic(out1,out3);
        return b2d(out3);
        break;
    case 13: //Shift A - Right arithmetic
        shiftRightArithmetic(out1,out3);
        return b2d(out3);
        break;
    case 14: //Shift A - Left circular
        shiftLeftCircular(out1,out3);
        return b2d(out3);
        break;
    case 15: //Shift A - Right circular
        shiftRightCircular(out1,out3);
        return b2d(out3);
        break;
    }
}
int add(int a, int b)//Addition
{
    return a+b;
}
int subtract(int a,int b)//Subtraction
{
    return a-b;
}
int multiply(int a, int b)
{
    return a*b;
}

void AndWise(int a[],int b[],int *out)//Bitwise And Gate
{
    int i;
    for(i=3; i>=0; i--)
    {
        if(a[i]&&b[i])
        {
            out[i]=1;

        }
        else
        {
            out[i]=0;
        }
    }
}
void NandWise(int a[],int b[],int *out)//Bitwise Nand Gate
{
    int i;
    for(i=3; i>=0; i--)
    {
        if(!(a[i]&&b[i]))
        {
            out[i]=1;

        }
        else
        {
            out[i]=0;
        }
    }
}
void OrWise(int a[],int b[],int *out)//Bitwise Or Gate
{
    int i;
    for(i=3; i>=0; i--)
    {
        if(a[i]||b[i])
        {
            out[i]=1;

        }
        else
        {
            out[i]=0;
        }
    }
}
void XorWise(int a[],int b[],int *out)//Bitwise Xor Gate
{
    int i;
    for(i=3; i>=0; i--)
    {
        if((a[i]&&!b[i])||(b[i]&&!a[i]))
        {
            out[i]=1;

        }
        else
        {
            out[i]=0;
        }
    }
}
void onesComplement(int a[],int *out)//1's Complement
{
    int i;
    for(i=3; i>=0; i--)
    {
        out[i]=!a[i];
    }
}
void shiftLeftLogical(int a[],int *out)//Shift left logical
{
    int i;
    for(i=0; i<4; i++)
    {
        out[i]=a[i+1];
    }
    out[3]=0;
}
void shiftLeftArithmetic(int a[],int *out)//Shift left arithmetic
{
    int i;
    for(i=0; i<4; i++)
    {
        out[i]=a[i+1];
    }
    out[3]=0;
}
void shiftLeftCircular(int a[],int *out)//Shift left circular
{
    int i,mid=a[0];
    for(i=0; i<4; i++)
    {
        out[i]=a[i+1];
    }
    out[3]=mid;
}
void shiftRightLogical(int a[],int *out)//Shift right logical
{
    int i;
    for(i=3; i>=0; i--)
    {
        out[i]=a[i-1];
    }
    out[0]=0;
}
void shiftRightArithmetic(int a[],int *out)//Shift right arithmetic
{
    int i,mid=a[0];
    for(i=3; i>=0; i--)
    {
        out[i]=a[i-1];
    }
    out[0]=mid,out[1]=mid;
}
void shiftRightCircular(int a[],int *out)//Shift right circular
{
    int i,mid=a[3];
    for(i=3; i>=0; i--)
    {
        out[i]=a[i-1];
    }
    out[0]=mid;
}

void d2b(int x,int *out ) //Decimal to binary conversion
{
    int a;
    a=x;
    int i=0,j=3,mid[4];
    while (a)
    {
        mid[i] = a % 2;
        a = a / 2;
        i++;
    }
    for(i=0; i<4; i++)
    {
        out[i]=mid[j];
        j--;
        if(out[i]>1) out[i]=0;
    }
}


int b2d(int *in)//Binary to decimal conversion
{
    int i,e=3,total=0;
    for(i=0; i<4; i++)
    {
        if(in[i]==1) total+=pow(2,e);
        e--;
    }
    return total;
}
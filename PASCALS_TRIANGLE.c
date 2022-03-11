/******************************************************************************

" **** C PROGRAM FR DRAWING PASCALS TRIANGLE WITHOUT USEING FORMULA *** "
--------------------------------------------------------------------------

Here is the example to Pascals triangle for (a+b)^3
r=3

row-0 (i=0)                 1           //printing starts from (r-0)th (3rd)  index ends at  (r+0)th (3rd) 
row-1 (i=1)               1   1         //printing starts from (r-1)th (2rd)  index ends at  (r+1)th (4th) 
row-2 (i=2)             1   2   1       //printing starts from (r-2)th (1st)  index ends at  (r+2)th (5th)
row-3 (i=3)           1   3   3   1     //printing starts from (r-3)th (0th)  index ends at  (r+3)th (6th)
           
indicies:             0 1 2 3 4 5 6    

Thus in ith row: //printing will starts from (r-i)th index ends at  (r+i)th index,
In between series coefficients will be print at even indices ie. r-i+0, r-i+2, r-i+3,...,r+i
At odd indicies space will be printed, same thing is operated in lines of code from 64 to 71

Also before (r-i)th index and after (r+i) th index spaces has to print in each ith row,
 same thing is operated in lines of code from 57 to 60

*******************************************************************************/

#include <stdio.h>

int main()
{
    int r,a,b,i,j,k,c;
    int A[100],B[100];
    for(i=0;i<100;i++)
    {
        A[i]=0;  // To store coefficients of each row
        B[i]=0;  // To add 0 at start and end of previous row coefficients in order to find next row coefficients
    }
    
    printf("Enter the the number of rows\n");
    scanf("%d",&r);  //To store number of rows, basically power of (a+b)^r
    
    for(i=0;i<=r;i++)
    {   
        if(i==0) //if power is 0 i.e. (a+b)^0
        {
            A[0]=1;
        }
        else //if power is greater than 0 i.e. (a+b)^r
        {
            for(j=0;j<=i;j++)
            {
                A[j]=B[j]+B[j+1]; //To find next now coefficients using previous row coefficients
            }
        }
        
        c=0;  //used for printing elements of a row (A[]) serially
        for(k=0;k<=2*r;k++)   //2*r is the total number of entities to be print including spaces in each row
        {
            if((k<r-i)||(k>r+i))  //when in ith row spaces have to print at start and end of row elements
            {
                printf(" ");
            }
            else
            {   //actually in each row from index r-i to r+i numbers exists if you notice the pattern
                //To print those patterns we use "if((k>=r-i)&&(k<=r+i))" this check
                if((k-r+i)%2==0)  //in that pattern elements have to be print only at even index in you notice
                {
                    printf("%d",A[c++]);
                }
                else   // at odd places space have to be print in you notice
                {
                    printf(" ");
                }
            }
        }
        printf("\n");  //To switch printing to next row
        
        B[0]=0;
        for(k=1;k<=i+1;k++)   //used for saving B[] by including 0 at start and end for estimating next row elements
        {
            B[k]=A[k-1];  
        }
        B[k+1]=0;
        
    }
    
    return 0;
}
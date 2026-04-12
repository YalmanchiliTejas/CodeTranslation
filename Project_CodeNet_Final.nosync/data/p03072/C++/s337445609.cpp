#include <stdio.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<complex>
#include<vector>
#include <climits>

using namespace std;


int main(void)
{
    int n,H[30],i,m,count=0;

    scanf("%d",&n);

    
    for(i=0;i<n;i++)
    {
        scanf("%d",&H[i]);

        for(m=0;m<i;m++)
        {
            if(H[i]<H[m]) break;
            else if(m==i-1) count++;
            
        }
    }


    printf("%d",count+1);
    cout << endl;

    return 0;
}
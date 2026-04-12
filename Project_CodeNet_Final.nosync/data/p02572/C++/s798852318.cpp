#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n; 

    cin>>n; 

    long long int a[n],p = pow(10 ,9) + 7,sum =0,prod =0;


    for(int i=0 ; i<n;i++ )
    {
        cin>>a[i];
        sum += a[i];
        sum %= p; 
    }

    for(int i=0  ; i<n;i++ )
    {
        sum -= a[i];

        if(sum < 0 )
        sum += p; 


        prod += sum*a[i];
        prod %= p ; 


    }

    

    cout<<prod; 


}
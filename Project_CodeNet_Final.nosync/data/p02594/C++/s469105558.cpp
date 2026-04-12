#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi 3.1415926535897932384626433
#define MAX 100000000000000000
#define sz = LLONG_MAX;

//char alpha[26] = {'a' ,'b','c', 'd', 'e', 'f' ,'g', 'h', 'i', 'j', 'k', 'm' ,'n' ,'o' ,'p' ,'q', 'r' ,'s', 't', 'u', 'v' ,'w' ,'x' ,'y', 'z'};

//Bits
/*
    Number of leading zeroes: builtin_clz(x)
    Number of trailing zeroes : builtin_ctz(x)
    Number of 1-bits: __builtin_popcount(x)

    1<<0, this means shifting of binary digit 1 by 0 positions to the left and after the operation, the result will be ‘1’
    1<<1, this means shifting of binary digit 1 by 1 position to the left and after the operation, the result will be ‘10’
    1<<2, this means shifting of binary digit 1 by 2 positions to the left and after operation, the result will be ‘100’

    1>>0, this means shifting of binary digit 1 by 0 positions to the right and after operation, the result will be ‘0’
    number>>1, when number = 4 in decimal and 100 in binary, this means shifting of binary representation of number right by 1 position and after the operation, the result will be ‘10’ i.e. 2, in decimal.

*/



//Factorial
ll fac(ll n)
{
    ll p=1;
    for(ll i=n;i>0;i--)
    {
        p*=i;
    }
    return p;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll test_case=1;    //cin>>test_case;

    while(test_case--)
    {
        ll x;
        cin>>x;
        if(x<30)
            cout<<"No\n";
        else
            cout<<"Yes\n";






    //Case_Ends_Here :)
    }
}

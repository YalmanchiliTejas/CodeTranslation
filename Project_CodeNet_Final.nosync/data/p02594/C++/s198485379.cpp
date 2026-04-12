// The moment you think of giving up you have already lost the battle
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long int ll;
typedef long double dl;
#define PI  3.14159265358979323846
#define Mod 1000000007
ll fast(ll n,ll a,ll m)
{
    if(n==0)
        return 1;
    else if(n==1)
        return a;
    else
    {
        ll r=fast(n/2,a,m);
        if(n%2==0)
        {
            return (((r%m)*(r%m))%m);
        }
        else
        {
            return (((((r%m)*a)%m)*r)%m);
        }

    }
}
int main()
{
   ll X;
   cin>>X;
   if(X>=30)
    cout<<"Yes";
   else
    cout<<"No";
}

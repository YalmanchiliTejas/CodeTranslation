#include <bits/stdc++.h>
#define ll long long
const long double PI=acos(-1);
using namespace std;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
bool prime(ll x)
{
    if(x==2)
    {
        return true;
    }
    else if(x<2||x%2==0)
    {
        return false;
    }
    else
    {
        for(int i=3;i*i<=x;i+=2) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
}
int main()
{
   int x;
   cin>>x;
   if(x>=30)
       cout<<"Yes"<<endl;
   else
       cout<<"No"<<endl;

}

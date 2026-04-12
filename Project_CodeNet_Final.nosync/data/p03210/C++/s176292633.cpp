#include <bits/stdc++.h>
using namespace std;

using ll =long long;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main()
{
int X;
  cin>>X;
  if(X==3||X==5||X==7){
    cout<<"YES"<<endl;
  }else{cout<<"NO"<<endl;}
}


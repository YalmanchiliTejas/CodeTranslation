#include<bits/stdc++.h>
using namespace std;
/*********ANISH***********ANISH*************ANISH***********ANISH******/
#define pb push_back
#define ll long long
#define ff first
#define ss second
ll max(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll min(ll a,ll b)
{
    if(a<b) return a;
    return b;
}
int lcm(int a, int b)  
{  
    return (a*b)/__gcd(a, b);  
}  
/********ANISH************ANISH*************ANISH**********ANISH*********/
int main()
{
  int test;
  test=1;
  while(test--)
  {
     int x;
     cin>>x;
     if(x>=30) cout<<"Yes";
     else cout<<"No";
  }
}

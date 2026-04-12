#include <bits/stdc++.h>
using namespace std;
//*******************
// Mahmoud Magdy    *
//*******************
#define ll long long
#define endl "\n"

void fast()
{
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}
inline int D()
{
    int m ;
    cin>>m;
    return m ;
}
inline ll lD()
{
    ll m ;
    cin>>m;
    return m ;
}
inline double dD()
{
    double m ;
    cin>>m;
    return m ;
}
int main()
{
  fast();
  int n=D();
  int x=n/15;
  ll sum1=(800*n)-(x*200);
  cout<<sum1<<endl;

}


#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll powll(ll a,ll n){
  if(n==0)
  {
    return 1;
  }
  return powll(a,n-1)*a;
}

int main() {
   ll i,j,k;
    ll n,m;
    cin >> n>>m;

    if(n==m)
    {
      cout<<"Yes"<<endl;
    }else
    {
 cout <<  "No"<< endl;
    }
 
}

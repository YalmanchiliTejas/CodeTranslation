#include <bits/stdc++.h>
#include <cstdlib>  
#include <cmath>
#include <string>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P= pair<ll,ll>;
const ll MOD = 1000000007;
int main() {
    ll N;
    cin>>N;
    vector<ll> A(N);
    ll sum=0;
    ll answer=0;
    rep(i,N){
      cin>>A[i];
      sum+=A[i];
      sum%=MOD;
    }
    for(int i=0;i<N;i++)
    {
      sum-=A[i];
      if(sum<0)sum+=MOD;
      answer +=A[i]*sum;
      answer %=MOD;
    }
    //if(D/S>T)cout<<"No"<<endl;
    cout<<answer<<endl;
    return 0;
}
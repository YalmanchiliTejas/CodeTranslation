#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n);++i)
const int INF =1001001001;
using ll=long long;
using P = pair<int,int>;
using Graph =vector<string>;
Graph field;
queue<P> q;

int main() {
  ll c=1000000007;
  ll ans,n,ans1,an;
  ans=0;
  ans1=0;
  cin>>n;
  rep(i,n){
    ll a;
    cin>>a;
    ans=(ans+a)%c;
    ans1=(ans1+(a*a)%c)%c;
  }
  an=((ans*ans)%c-ans1);
  if(an<0)an=an+c;
  an *= (c + 1) / 2;
  cout<<an%c<<endl;
}


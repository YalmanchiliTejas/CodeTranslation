#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define is(a, b) a == b
#define len(v) ll(v.size())

const ll mod=1e9+7;

//vector書き出し
template <class T>
void cout_vec(const vector<T> &vec1){
  rep(i,len(vec1)){
    cout<<vec1[i]<<' ';
  }
  cout<<'\n';
}

typedef pair<ll,ll> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    vector<ll> mo(n+1);
    FOR(b,1,n+1){
      mo[b]=n%b;
    }
    FOR(b,1,n+1){
      if(b<=k){
        continue;
      }
      ans+=((n/b)+1)*(max((ll)0,mo[b]-k+1))+(n/b)*(b-1-max((ll)mo[b],(ll)k-1));
      //out<<b<<' '<<ans<<'\n';
    }
    if(k==0){
        ans=ans-n;
    }
    cout<<ans<<endl;
}

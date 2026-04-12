#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    char a[10][10];
    FOR(i,1,h+1)FOR(j,1,w+1) cin>>a[i][j];
    int now=1;
    FOR(i,1,h+1)FOR(j,1,w+1){
      if(a[i][j]=='#'){
        if(j<now){
          cout<<"Impossible"<<endl;
          return 0;
        }else{
          now=j;
        }
      }
    }
    cout<<"Possible"<<endl;
}
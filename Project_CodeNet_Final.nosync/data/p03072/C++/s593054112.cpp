#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> h(n);
    rep(i,n){
      cin>>h[i];
    }
    int ans=1;
    FOR(i,0,n){
      FOR(j,0,i){
        if(h[i]<h[j]){
          break;
        }
        if(j==i-1){
          ans++;
        }
      }
    }
    cout<<ans<<endl;
}
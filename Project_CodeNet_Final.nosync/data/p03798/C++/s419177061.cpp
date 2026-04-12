#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  rep(j,4){
    vector<int> v(n,-1);
    if(j==0) {v[0]=1; v[1]=1;}
    if(j==1) {v[0]=1; v[1]=0;}
    if(j==2) {v[0]=0; v[1]=1;}
    if(j==3) {v[0]=0; v[1]=0;}
    bool f=1;
    rep(i,n){
      if(v[i]==1&&s[i]=='o'||v[i]==0&&s[i]=='x'){
        if(i==0) v[n-1]=v[1];
        if(i==n-2){
          if(v[n-3]!=v[n-1]) f=0;
          else continue;
        }
        if(i==n-1&&v[n-2]!=v[0]) f=0;
        if(0<i&&i<n-1) v[i+1]=v[i-1];
      }
      else{
        if(i==0) v[n-1]=1-v[1];
        if(i==n-2){
          if(v[n-3]==v[n-1]) f=0;
          else continue;
        }
        if(i==n-1&&v[n-2]==v[0]) f=0;
        if(0<i&&i<n-1) v[i+1]=1-v[i-1];
      }
    }
    if(f){
      rep(i,n){
        if(v[i]==1) cout << 'S';
        else cout << 'W';
      }cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
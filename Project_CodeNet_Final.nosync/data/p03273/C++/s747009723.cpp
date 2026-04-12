#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define fs first
#define sc second
typedef pair<ll, ll> l_l;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
    }
  }
  vector<bool>f(h,false);
  vector<bool>flag(w,false);  
   rep(i,h){
    rep(j,w){
      if(a[i][j]=='#')f[i]=true;
    }
  }
  rep(j,w){
    rep(i,h){
      if(a[i][j]=='#')flag[j]=true;
    }
  }
  rep(i,h){
    if(!f[i]) continue;
    rep(j,w){
      if(flag[j])cout<<a[i][j];
    }
    cout<<endl;
  }
}

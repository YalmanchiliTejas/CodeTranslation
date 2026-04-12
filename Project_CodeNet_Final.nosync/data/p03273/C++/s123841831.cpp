#include <stdlib.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

int main() {
  long long a,b;
  cin>>a>>b;
  vector<vector<char>> data(a,vector<char>(b));
  rep(i,a){
    rep(j,b){
      cin>>data.at(i).at(j);
    }
  }
  rep(i,a){
    bool f3=false;
    rep(j,b){
      int numy=i;int numx=j;
      bool f1=true;bool f2=true;
      rep(k,a){
        if(data.at(k).at(numx)=='#'){
          f1=false;
        }
      }
      rep(l,b){
        if(data.at(numy).at(l)=='#'){
          f2=false;
        }
      }
      if(f1||f2){
      }
      else{
        cout<<data.at(numy).at(numx);
        f3=true;
      }
    }
    if(f3){
      cout<<endl;
    }
  }
}

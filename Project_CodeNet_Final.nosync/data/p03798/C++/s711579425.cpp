#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);++i)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;--i)
#define rep1(i,n) for(int (i)=1;(i)<=(n);++i)
#define rrep1(i,n) for(int (i)=(n);(i)>=1;--i)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;
ll N;
string s;
bool b[100001];

vector<ll> calc(ll x,ll y){
  vector<ll> v;
  v.pb(x);
  v.pb(y);
  rep1(i,N-2){
    v.pb(v[i] ^ b[i] ^ v[i-1] );
  }
  if (! ( ( (v[0]==v[v.size()-2]) ^ b[v.size()-1] ^ v[v.size()-1] ) && ((v[1]==v[v.size()-1]) ^ b[0] ^ v[0] ) ) ){
    v.clear();
  }
  return v;
}

int main(){
  cin>>N;
  cin>>s;
  rep(i,N){
    if(s[i]=='o') b[i]=0;
    else b[i]=1;
  }
  string a;
  rep(i,2) rep(j,2){
    vector<ll> ans = calc(i,j);
    if(ans.size()){
      rep(i,N){
        if(ans[i]) a+="W";
        else a+="S";
      }
      cout<<a<<endl;
      return 0;
    }
  }
  puts("-1");
  return 0;
}

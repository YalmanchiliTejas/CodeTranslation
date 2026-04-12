#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#include<random>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

ll gcd(ll n, ll m) {
	ll tmp;
	while (m!=0) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m) {
	return abs(n * m) / gcd(n, m);//gl=xy
}
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;
//ここから

void solve(){
  //0:羊,1:狼
  int n;
  string s;
  cin>>n>>s;
  vector<int>v(n);
  rep(a,2){//先頭の置き方
    rep(b,2){//2番目の置き方
    bool ok=true;
      v[0]=a,v[1]=b;
      for(int i=2;i<n;++i){
        if(s[i-1]=='o'){
          if(v[i-1]==0)v[i]=v[i-2];
          else v[i]=v[i-2]^1;
        }
        else {
          if(v[i-1]==0)v[i]=v[i-2]^1;
          else v[i]=v[i-2];
        }
      }
      rep(i,n){
        //if(a==0&&b==0)cout<<v[i]<<endl;
        if(s[i]=='o'){
          if(v[i]==0&&v[(i-1+n)%n]!=v[(i+1)%n])ok=false;
          else if(v[i]==1&&v[(i-1+n)%n]==v[(i+1)%n])ok=false;
        }
        else{
          if(v[i]==0&&v[(i-1+n)%n]==v[(i+1)%n])ok=false;
          else if(v[i]==1&&v[(i-1+n)%n]!=v[(i+1)%n])ok=false;
        }
      }
      if(ok){
        rep(i,n){
          if(v[i]==1)cout<<"W";
          else cout<<"S";
        }
        cout<<"\n";
        return;
      }
    }
  }
  
  cout<<-1<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}

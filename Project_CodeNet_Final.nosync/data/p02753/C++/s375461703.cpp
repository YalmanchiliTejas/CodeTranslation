#include <bits/stdc++.h>
//#pragma once
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<double,double> P;
const ll INF = 1e16;
const int MOD = 1000000007;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 



///////////////////////___modpow___////////////////////

////////////////////////////////////////////////////////////////////


signed main(){
  string s;cin>>s;
  bool a = false, b = false;
  rep(i,s.length()){
    if(s[i] == 'A')a = true;
    else b = true;
  }
  if(a && b)cout << "Yes" << endl;
  else cout << "No" << endl;
}




/*
 * Welcome to my code!
 * -------------------------------------------- *
 * author : lynmisakura(twitter : @andoreiji11)
 */

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

//Simple Array Input
#define SAI int n;cin >> n;vi a(n);ain(a)
//Simple Graph Input
#define SGI(m) for(int i=0;i<m;i++){int a,b;cin >> a >> b;g[--a].pb(--b);g[b].pb(a);}
//Simple Tree Input
#define STI SGI(n-1)

typedef long long ll;
typedef long long integer;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){
    for(int i=0;i<a.size();i++)cout << a[i] << (i < a.size()-1 ? ' ' : '\n');
}

ll dp[110][4][2];

int main(void){
  string s;cin >> s;
  int n = s.length();
  
  int k;cin >> k;
  
  dp[0][0][0] = 1;
  
  rep(i,n){
    rep(j,k+1){
      rep(ov,2){
        rep(num,10){
          
          int ni = i+1,nj = j,nov = ov;
          
          if(num == 0){
            nov = ov || (s[i] != '0');
          }else{
            if(j == k)continue;
            nj = j + 1;
            
            if(!ov && s[i] - '0' < num)continue;
            
            nov = ov || (s[i] - '0' > num);
          }
          
          dp[ni][nj][nov] += dp[i][j][ov];
        }
      }
    }
  }
  
  cout << dp[n][k][0] + dp[n][k][1] << '\n';
  
  return 0;
}

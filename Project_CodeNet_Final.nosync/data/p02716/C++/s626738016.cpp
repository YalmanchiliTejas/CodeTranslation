/*
* Welcome to my code!
*---------------------------------------------*
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

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){ int sz = a.size();
for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////

ll dp[200020][3];

int main(int argc, char const *argv[])
{
	ioboost();
	int n;cin >> n;
	vl a(n);
	rep(i,n)cin >> a[i];

	int ex = 1 + (n % 2 == 1);

	rep(i,200020)rep(j,3)dp[i][j] = -LONG_MAX / 10;
	dp[0][0] = 0;

	rep(i,n){
		rep(j,ex + 1){
			if(j < ex){
				if((i + j) % 2 == 0){
					chmax(dp[i+1][j+1],dp[i][j]);
					chmax(dp[i+1][j],dp[i][j] + a[i]);
				}else{
					chmax(dp[i+1][j],dp[i][j]);
				}
			}else{
				if((i + j) % 2 == 0){
					chmax(dp[i+1][j],dp[i][j] + a[i]);
				}else{
					chmax(dp[i+1][j],dp[i][j]);
				}
			}
		}
	}
	
	if(n % 2 == 0){
		cout << max({dp[n][0],dp[n][1]}) << '\n';
	}else{
		cout << max({dp[n][1],dp[n][2]}) << '\n';
	}	

	return 0;
}

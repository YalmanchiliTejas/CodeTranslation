/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        fozubaoyou    pass System Test!
        quoted from "https://codeforces.com/contest/472/submission/7996840"
*/
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define fin(ans) cout<<(ans)<<endl
#define STI(s) atoi(s.c_str())
#define mp(p,q) make_pair(p,q)
#define pb(n) push_back(n)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define Sort(a) sort(a.begin(),a.end())
#define Rort(a) sort(a.rbegin(),a.rend())
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);};};
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL<<60;

vvi v(8);
ll ans=0;

void dfs(int pos, vector<bool> passed, int passnum, int n){
	passed[pos]=true;
	if(passnum==n){
		ans++;
	}
	for(int i=0;i<v[pos].size();i++){
		if(!passed[v[pos][i]])dfs(v[pos][i],passed,passnum+1,n);
	}
}

int main(void){
    
	int n,m;
	cin>>n>>m;
	rep(i,m){
		int a,b;
		cin>>a>>b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	vector<bool> passed(n,false);
	passed[0]=true;
	dfs(0,passed,1,n);
	fin(ans);
	

}

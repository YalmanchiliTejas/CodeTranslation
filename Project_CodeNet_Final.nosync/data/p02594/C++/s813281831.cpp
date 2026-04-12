/*
NAME:
 ___   _      _   ___  
/ __| /_\    /_\ |   \ 
\__ \/ _ \  / _ \| |) |
|___/_/ \_\/_/ \_\___/ 

lang: 
  ___   _      _   
 / __)_| |_  _| |_ 
( (__(_   _)(_   _)
 \___) |_|    |_|  

*/
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>
 
using namespace std;
 
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef long l;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<l> vl;
typedef vector<ll> vll;

const int INF = 1 << 29;
const int MOD = 1e9 + 7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
 
void solve(){
	int n;
	cin>>n;
	if(n>=30) cout<<"Yes";
	else cout<<"No";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
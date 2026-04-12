#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<complex>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using Complex = complex<double>;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1145141919810364364LL;
double PI = acos(-1.0);
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)


const int SZMAX = 100;
ll dp[SZMAX + 5][10][10];
int nxtj(int j,int l,char c) {
	if (j == 1)return 1;
	int num = c - '0';
	if (l < num)return 1;
	else if (l == num)return 0;
	else return 2;
}
int nxtk(int k,int l){
	if (l == 0)return k;
	else return min(k + 1,4);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string N;
	int K;
	cin >> N >> K;
	int sz = N.size();
	reverse(all(N));
	dp[sz][0][0] = 1;
	for (int i = sz; i >= 1; i--){
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k <= 3; k++) {
				for (int l = 0; l <= 9; l++) {
					dp[i-1][nxtj(j,l,N[i-1])][nxtk(k,l)] += dp[i][j][k];
				}
			}
		}
	}
	puts(dp[0][0][K] + dp[0][1][K]);
	
	return 0;
}
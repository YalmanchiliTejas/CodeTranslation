#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
#include<utility>
#include<map>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define range(a) a.begin(), a.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define MP make_pair
using Graph = vector<vector<int>>;
const unsigned long long mod = 1e9 + 7;
const long long INF = 1LL<<60;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll N, s=0, ans=0, tot=0;
	ll X, M, len=0;
	cin >> N >> X >> M;
	vector<ll> id(M,-1);
	vector<ll> a;
	while(id[X]==-1){
		a.push_back(X);
		id.at(X) = len;
		len++;
		tot += X;
		X = (X * X) % M;
	}

	
	if (N <= len){
		FOR(i, 0, N){
			ans += a.at(i);
		}
	}

	else{
		ll c = len - id.at(X); //ループ回数
		FOR(i, id.at(X), len)
			s += a.at(i);
		ans += tot;
		N -= len;
		ans += (N / c) * s;
		N %= c;
		FOR(i, 0, N)
			ans += a.at(id.at(X) + i);
	}

	cout << ans << endl;

	return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

int n;

int remainS[555];
bool okS[555];
int remainT[555];
bool okT[555];
int uBit[555];
int vBit[555];
int mp[555][555];
unsigned long long ans[555][555];
int s[555];
int t[555];
unsigned long long u[555];
unsigned long long v[555];

void init(int num){
	REP(i, n){
		uBit[i] = ((u[i] >> num) & 1);
		vBit[i] = ((v[i] >> num) & 1);
		remainS[i] = n;
		remainT[i] = n;
		okS[i] = false;
		okT[i] = false;
	}
	REP(i, n)REP(j, n)mp[i][j] = -1;
}

void post(int num){
	REP(i, n)REP(j, n)ans[i][j] |= ((unsigned long long)mp[i][j] << num);
}

bool s_first(int y){
	if(s[y] == uBit[y])return true;

	REP(j, n){
		if(mp[y][j] != -1){
			if(mp[y][j] != uBit[y])return false;
			continue;
		}
		mp[y][j] = uBit[y];
		remainS[y]--;
		remainT[j]--;
	}
	return okS[y] = true;;
}

bool t_first(int x){
	if(t[x] == vBit[x])return true;

	REP(i, n){
		if(mp[i][x] != -1){
			if(mp[i][x] != vBit[x])return false;
			continue;
		}
		mp[i][x] = vBit[x];
		remainS[i]--;
		remainT[x]--;
	}
	return okT[x] = true;;
}

bool s_check(int y){
	if(okS[y])return true;
	int and_num = 1;
	int or_num = 0;
	bool flag = true;
	REP(j, n){
		if(mp[y][j] == -1)continue;
		and_num &= mp[y][j];
		or_num |= mp[y][j];
		flag = false;
	}
	if(flag)return false;
	if(s[y] == 0 && uBit[y] != and_num)return false;
	if(s[y] == 1 && uBit[y] != or_num)return false;
	return okS[y] = true;;
}

bool t_check(int x){
	if(okT[x])return true;
	int and_num = 1;
	int or_num = 0;
	bool flag = true;
	REP(i, n){
		if(mp[i][x] == -1)continue;
		and_num &= mp[i][x];
		or_num |= mp[i][x];
		flag = false;
	}
	if(flag)return false;
	if(t[x] == 0 && vBit[x] != and_num)return false;
	if(t[x] == 1 && vBit[x] != or_num)return false;
	return okT[x] = true;;
}

bool s_do(int y, queue<pair<char, ll> > &q){
	if(s_check(y))return true;
	REP(j, n){
		if(mp[y][j] != -1)continue;
		mp[y][j] = uBit[y];
		remainS[y]--;
		remainT[j]--;
		if(!t_check(j)){
			if(remainT[j] == 0)return false;
			if(remainT[j] == 1)q.push(MP('t', j));
		}
		return okS[y] = true;;
	}
	return false;
}

bool t_do(int x, queue<pair<char, ll> > &q){
	if(t_check(x))return true;
	REP(i, n){
		if(mp[i][x] != -1)continue;
		mp[i][x] = vBit[x];
		remainS[i]--;
		remainT[x]--;
		if(!s_check(i)){
			if(remainS[i] == 0)return false;
			if(remainS[i] == 1)q.push(MP('s', i));
		}
		return okT[x] = true;;
	}
	return false;
}

bool solve(){
	REP(i, n){
		if(!s_first(i))return false;
		if(!t_first(i))return false;
	}
	queue<pair<char, ll> > q;
	REP(i, n){
		if(!s_check(i)){
			if(remainS[i] == 0)return false;
			if(remainS[i] == 1)q.push(MP('s', i));
		}
		if(!t_check(i)){
			if(remainT[i] == 0)return false;
			if(remainT[i] == 1)q.push(MP('t', i));
		}
	}
	while(1){
		if(q.empty()){
			REP(i, n){
				if(!s_check(i)){
					if(remainS[i] == 0)return false;
					q.push(MP('s', i));
					break;
				}
				if(!t_check(i)){
					if(remainT[i] == 0)return false;
					q.push(MP('t', i));
					break;
				}
			}
		}
		if(q.empty())break;

		char type = q.front().FI;
		int num = q.front().SE;
		q.pop();
		if(type == 's'){
			if(!s_do(num, q))return false;
		}
		else {
			if(!t_do(num, q))return false;
		}
	}

	REP(i, n)REP(j, n)if(mp[i][j] == -1)mp[i][j] = 0;
	return true;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	cin >> n;
	REP(i, n)cin >> s[i];
	REP(i, n)cin >> t[i];
	REP(i, n)cin >> u[i];
	REP(i, n)cin >> v[i];

	REP(i, 64){
		init(i);
		if(!solve()){cout << -1 << endl;return 0;};
		post(i);
	}

	REP(i, n){
		REP(j, n){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

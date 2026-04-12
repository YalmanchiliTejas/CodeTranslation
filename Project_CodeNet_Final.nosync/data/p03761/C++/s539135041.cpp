#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
 
using namespace std;
 
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
 
long gcd(long a, long b){
	if (a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}
 
long lcm(long a, long b){
	return (a*b) / gcd(a,b);
}
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a < b) { a = b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a > b) { a = b; return 1; } return 0; }
 
typedef long long ll;

const ll INF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-10;

int c[50][26];
char s[50][50];
int cnt[26];

int main(){
	int n;
	
	cin >> n;
	
	REP(i,n){
		scanf("%s", s[i]);
		
		int len = strlen(s[i]);
		
		REP(j,len){
			c[i][s[i][j] - 'a']++;
		}
	}
	
	REP(i,26){
		cnt[i] = 5000;
		
		REP(j,n){
			cnt[i] = min(cnt[i],c[j][i]);
		}
	}
	
	REP(i,26){
		REP(j,cnt[i]) printf("%c", 'a'+i);
	}
	
	puts("");
	
	return 0;
}
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>
#include<bitset>
#include<tuple>
#include<cassert>
#include<time.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)

typedef long long i64;
typedef pair<i64,i64> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


string s;
int k;

i64 mod_pow(i64 x, i64 y, i64 mod){
	i64 res = 1;
	while(y > 0){
		if(y & 1) res = res * x % mod;
		x = x*x %mod;
		y >>= 1;
	}
	return res;
}

int main(){
	cin >> s;
	cin >> k;
	int n = s.size();
	
	P p[3];
	int c = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != '0'){
			p[c] = P(s[i]-'0', n-i-1);
			c++;
		}
		if(c == k) break;
	}
	
	i64 ans = 0;
	if(k == 3){
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k < n; k++){
				if(k < n-1){
					ans += 9 * 9 * 9;
				}
				else{
					if(p[1].second > j){
						ans += 9 * 9 * p[0].first;
					}
					else if(p[1].second == j && p[2].second > i){
						ans += 9 * p[1].first;
						ans += 9 * 9 * (p[0].first-1);
					}
					else if(p[1].second == j && p[2].second == i){
						ans += (p[2].first);
						ans += 9 * (p[1].first-1);
						ans += 9 * 9 * (p[0].first-1);
					}
					else if(p[1].second == j){
						ans += 9 * (p[1].first-1);
						ans += 9 * 9 * (p[0].first-1);
					}
					else{
						ans += 9 * 9 * (p[0].first-1);
					}
				}
				ans %= INF;
			}
		}
	}
	}
	if(k == 2){
		for(int j = 0; j < n; j++){
			for(int k = j+1; k < n; k++){
				if(k < n-1){
					ans += 9 * 9;
				}
				else{
					if(p[1].second > j){
						ans += 9 * p[0].first;
					}
					else if(p[1].second == j){
						ans += 9 * (p[0].first-1);
						ans += p[1].first;
					}
					else{
						ans += 9 * (p[0].first-1);
					}
				}
				ans %= INF;
			}
		}
	}
	if(k == 1){
		for(int k = 0; k < n; k++){
			if(k < n-1){
				ans += 9;
			}
			else{
				ans += p[0].first;
			}
			ans %= INF;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
bool S[200000];
long DP[4][200000];
long C[100000];
void Calc(){
	int N = rei();
	int M = rei();
	string s = res();
	for(int i=0;i<M;i++){
		S[i] = s[i] == s[0];
	}
	long ans;
	{
		bool AllSame = true;
		for(int i=0;i<M;i++){
			AllSame &= S[i];
		}
		if(AllSame){
			DP[0][0] = 1;
			DP[3][0] = 1;
			for(int i=1;i<N;i++){
				DP[0][i] = DP[1][i-1];
				DP[1][i] = (DP[1][i-1]+DP[0][i-1]) % mod;
				DP[2][i] = DP[3][i-1];
				DP[3][i] = (DP[3][i-1]+DP[2][i-1]) % mod;
			}
			ans = DP[1][N-1] + DP[2][N-1] + DP[3][N-1];
			ans %= mod;
			cout << ans << endl;
			return;
		}
	}
	if(N % 2 != 0){
		cout << 0 << endl;
		return;
	}
	int K = -1;
	{
		int before = 0;
		for(int i=0;i<M;i++){
			if(S[i]){
				before++;
			}
			else{
				if(K == -1){
					K = (before+2)/2;
				}
				else{
					if(before % 2 != 0){
						K = min(K,(before+2)/2);
					}
				}
				before = 0;
			}
		}
	}
	C[0] = 1;
	long sum = 1;
	for(int i=1;i<N/2;i++){
		C[i] = sum;
		sum += C[i];
		if(i-K >= 0){
			sum += mod - C[i-K];
		}
		sum %= mod;
	}
	ans = 0;
	for(int i=1;i<=min(N/2,K);i++){
		ans += i*C[N/2-i]%mod;
	}
	ans *= 2;
	ans %= mod;
	cout << ans << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}
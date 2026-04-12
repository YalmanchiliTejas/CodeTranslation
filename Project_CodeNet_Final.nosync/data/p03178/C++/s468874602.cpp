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
long DP[10001*100];
long DP2[10001*100];
void Calc(){
	string S = res();
	int D = rei();
	DP2[0] = 1;
	for(int i=0;i<S.length();i++){
		int p = S[i] - '0';
		for(int j=0;j<D;j++){
			for(int k=0;k<p;k++){
				DP[(i+1)*100 + (j+k) % D] += DP[i*100 + j] + DP2[i*100 + j];
			}
			DP[(i+1)*100 + (j+p) % D] += DP[i*100 + j];
			DP2[(i+1)*100 + (j+p) % D] += DP2[i*100 + j];
			for(int k=p+1;k<10;k++){
				DP[(i+1)*100 + (j+k) % D] += DP[i*100 + j];
			}
		}
		for(int j=0;j<D;j++){
			DP[(i+1)*100 + j] %= mod;
			DP2[(i+1)*100 + j] %= mod;
		}
	}
	long ans = DP[S.length()*100] + DP2[S.length()*100] + mod - 1;
	cout << ans % mod << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}
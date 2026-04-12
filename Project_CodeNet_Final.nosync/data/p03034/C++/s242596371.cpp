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
#include <functional>

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
long S[100000]; 
int last[100000];
void Calc(){
	int N = rei();
	//(A-B)*k
	//N-1 - (A-B)*k
	//N-1-A = (A-B)*(K-1)
	for(int i=0;i<N;i++){
		S[i] = rei();
	}
	long ans = 0;
	for(int i=1;i<=N-1;i++){
		long sum = 0;
		for(int j=0;j<N;j+=i){
			if(last[j] == i || last[N-1-j] == i || j == N-1-j || N-1-j < i){
				break;
			}
			sum += S[j] + S[N-1-j];
			last[j] = i;
			last[N-1-j] = i;
			ans = max(ans,sum);
		}
	}
	cout << ans << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}
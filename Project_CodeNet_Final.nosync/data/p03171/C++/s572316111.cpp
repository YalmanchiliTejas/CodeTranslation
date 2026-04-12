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
long DP[3000*3000];
long A[3000];
void Calc(){
	int N = rei();
	for(int i=0;i<N;i++){
		A[i] = rel();
	}
	for(int i=0;i<N;i++){
		DP[i*3000+i] = A[i];
	}
	for(int i=1;i<N;i++){
		for(int j=0;j+i<N;j++){
			DP[j*3000+(j+i)] = max(A[j]-DP[(j+1)*3000+j+i],A[j+i]-DP[j*3000+j+i-1]);
		}
	}
	cout << DP[N-1] << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}
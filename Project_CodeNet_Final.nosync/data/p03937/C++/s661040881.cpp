/*+lmake
 * STD = c++14
 * DEFINE += WAAUTOMATON
 */
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#ifdef WAAUTOMATON
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr<<v<<" ";
		return *this;
	}
} dbg;

void solve(long long H, long long W, vector<string> A){
	int x=0,y=0;
	if (A[0][0]!='#') throw 1;
	A[0][0]='.';
	while(x!=H-1 ||  y!=W-1) {
		if (x<H-1 && A[x+1][y]=='#' && y<W-1 && A[x][y+1]=='#') {
			throw 2;
		}
		if (x<H-1 && A[x+1][y]=='#') {
			++x;
			A[x][y]='.';
		} else if (y<W-1 && A[x][y+1]=='#') {
			++y;
			A[x][y]='.';
		} else throw 3;
	}
	for(const auto& i:A) {
		for(const auto& j:i) {
			if (j=='#') throw 4;
		}
	}
	puts("Possible");
}

int main(){
#ifdef WAAUTOMATON
	//freopen("in.txt","r",stdin);
#endif
	long long W;
	long long H;
	scanf("%lld",&H);
	vector<string> A(H-1+1);
	scanf("%lld",&W);
	for(int i = 0 ; i <= H-1 ; i++){
		cin >> A[i];
	}
	try {
	solve(H, W, A);
	} catch (int flag) {
		debug(flag);
		puts("Impossible");
	}
	return 0;
}


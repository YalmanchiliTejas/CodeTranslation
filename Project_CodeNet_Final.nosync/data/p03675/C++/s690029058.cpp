// #includes {{{
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

void solve(long long n, vector<long long> a){
	bool rev = false;
	deque<long long> d;
	REP(i,n){
		if(!rev){
			d.push_back(a[i]);
		}else{
			d.push_front(a[i]);
		}
		rev = !rev;
	}
	if(rev){
		reverse(ALL(d));
	}
	REP(i,n){
		cout<<d[i]<<" ";
	}
	cout<<endl;
}

int main(){	
	long long n;
	scanf("%lld",&n);
	vector<long long> a(n-1+1);
	for(int i = 0 ; i <= n-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(n, a);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define VSORT(v) sort(v.begin(), v.end())
#define DVSORT(v) sort(v.begin(), v.end(),greater<int>())
#define SORT(v, n) sort(v, v+n)
#define DSORT(v,n) sort(v, v+n,greater<int>())
#define vi vector<int>
#define pb push_back
#define P pair<int,int>


template <class T> void chmin(T&a, const T&b) { a = min(a,b); }
template <class T> void chmax(T&a, const T&b) { a = max(a,b); }

const double EPS =1e-9;
const long INF =2147483647;//32bit 2*1e+9
const long MOD =1e+9+7;
#define PI 3.14159265258979

int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

int main(void){
	char S[5]={'a','e','i','o','u'},c;
	cin>>c;

	REP(i,5){
		if(S[i]==c){
			puts("vowel");
			return 0;
		}
	}
	puts("consonant");
 return 0; 
}


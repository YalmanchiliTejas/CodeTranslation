#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define MOD (1000000007)
#define TO_STRING(VariableName) # VariableName
#define LOG(xx) if(DEBUG)cout<<TO_STRING(xx)<<"="<<xx<<" "<<endl;
#define LOG2(xx,yy) if(DEBUG)cout<<TO_STRING(xx)<<"="<<xx<<" "<<TO_STRING(yy)<<"="<<yy<<endl;
#define LOG3(xx,yy,z) if(DEBUG)cout<<TO_STRING(xx)<<"="<<xx<<" "<<TO_STRING(yy)<<"="<<yy<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,xx,yy,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(xx)<<"="<<xx<<" "<<TO_STRING(yy)<<"="<<yy<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

lli sum[200100];

void solve(){

	lli n;
	cin>>n;
	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];

	REP(i,0,n){
		sum[i+1] = sum[i]+a[i];
		sum[i+1]%=MOD;
	}

	lli ans = 0;
	REP(i,0,n-1){
		ans += (a[i]*(sum[n]))%MOD;
		ans %= MOD;
		ans += (MOD-(a[i]*(sum[i+1]))%MOD);
		ans %= MOD;
	}
	cout<<ans<<endl;

}

int main(){
	
    // cout << fixxed << setprecision(5);
    lli t=1;
    //cin>>t;
    while(t--)solve();

    return 0;
}

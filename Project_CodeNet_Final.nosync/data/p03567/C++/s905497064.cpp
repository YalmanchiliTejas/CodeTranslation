#include <bits/stdc++.h>
#define REP(i,n,N) for(ll i=(n);i<(ll) N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=(int) n;i--)
#define p(s) cout<<(s)<<endl
#define DEBUG(x,y) cout<<#x<<": "<<x<<" , "<<#y<<": "<<y<<endl;
#define CK(n,a,b) ((a)<=(n)&&(n)<=(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf=1e9+7;

string s;
int main(){
	cin>>s;
	bool flag=false;
	REP(i,0,s.size()-1){
		if(s[i]=='A'&&s[i+1]=='C') flag=true;
	}
	if(flag){
		p("Yes");
	}else{
		p("No");
	}

	return 0;
}

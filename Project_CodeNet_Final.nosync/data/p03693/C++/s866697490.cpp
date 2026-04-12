#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=(n);i<(int)N;i++)
#define p(s) cout<<(s)<<endl
#define ck(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf=1e9;

int main() {
	int r,g,b;
	cin>>r>>g>>b;
	int num=100*r+10*g+b;
	if(num%4==0){
		p("YES");
	}
	else p("NO");;
	return 0;
}

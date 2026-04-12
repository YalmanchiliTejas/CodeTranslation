#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;

int main(){
	int ans=0;
	int now=0;
	cin>>N;
	REP(i,N){
		int a;
		cin>>a;
		if(now<=a){
			now=a;
			ans++;
		}
	}
	cout<<ans<<endl;
}
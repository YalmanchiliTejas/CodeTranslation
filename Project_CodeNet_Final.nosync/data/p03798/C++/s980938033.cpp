#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)

signed main(){

	lli n;
	cin>>n;

	string s;
	cin>>s;

	REP(start,0,2)REP(side,0,2){
		lli ans[100100];
		REP(i,0,100100)ans[i]=-1;
		ans[0]=start;
		ans[1]=side;
		ans[n+2] = (ans[0]+ans[1]+(s.at(0)!='o'))%2;

		REP(i,1,n){
			ans[i+1] = (ans[i-1]+ans[i]+(s.at(i)!='o'))%2;
		}
		if(ans[0]==ans[n] && ans[n-1] == ans[n+2]){
			REP(i,0,n){
				if(ans[i]==0)cout<<"S";
				else cout<<"W";
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;

	return 0;
}
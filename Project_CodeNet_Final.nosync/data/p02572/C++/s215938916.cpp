#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void cmax(int&x,const int&y){x=x>y?x:y;}
void cmin(int&x,const int&y){x=x<y?x:y;}
const int mod=1e9+7;
void add(int&x,const int&y){x+=y;if(x>=mod)x-=mod;}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s=0;
	int n;
	cin>>n;
	vector<int>a(n);
	int ans=0;
	for(auto x:a){
		cin>>x;
		add(ans,1ll*x*s%mod);
		add(s,x);
	}
	cout<<ans<<'\n';
	return 0;
}

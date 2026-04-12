#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
string ans[4]={"SW","SS","WW","WS"};
int main(){	
	int n;cin>>n;bool ok=1;
	string s,t;cin>>s;
	for(int k=0;k<4;k++){
		t=ans[k];
	for(int i=1;i<n-1;i++,ok=1){
		if(t[i]=='S'){
			if(s[i]=='o') t+=t[i-1];
			else t+=(t[i-1]=='W')?'S':'W';
		}
		else {
			if(s[i]=='o') t+=(t[i-1]=='W')?'S':'W';
			else t+=t[i-1];
		} 
	}
	//cout<<t<<endl;
	if(t[0]=='S'){
		if(s[0]=='o') ok&=(t[1]==t[n-1]);
		else ok&=(t[1]!=t[n-1]);
	}
	else {
			if(s[0]=='x') ok&=(t[1]==t[n-1]);
		else ok&=(t[1]!=t[n-1]);
	}
	if(t[n-1]=='S'){
		if(s[n-1]=='o') ok&=(t[0]==t[n-2]);
		else ok&=(t[0]!=t[n-2]);
	}
	else {
		if(s[n-1]=='x') ok&=(t[0]==t[n-2]);
		else ok&=(t[0]!=t[n-2]);
	}
	if(ok) break;
	}
	if(ok) cout<<t;
	else puts("-1");
	return 0;
}
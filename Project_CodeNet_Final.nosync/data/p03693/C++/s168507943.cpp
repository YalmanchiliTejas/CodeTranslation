#include<bits/stdc++.h>
#define int long long
const int inf=8938103643641919514ll;
const int mod=1000000007ll;
const int dd[]={0,-1,0,1,0};
using namespace std;
int a,b,c,d;
int p[200000];
signed main(){
	cin>>a>>b>>c;
	int ans=a*100+b*10+c;
	if(ans%4==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
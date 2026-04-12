#include <iostream>
#include <iomanip>
#include <map>
#include <string.h>

using namespace std;

const int MOD = 998244353;

int me[3001][3001];
int a[3000];
int n,s;

int dp(int ac, int r){
	if(me[ac][r]!=-1)return me[ac][r];
	if(r==0)return me[ac][r]=n-ac+1;
	if(ac==n)return me[ac][r]=0;
	me[ac][r] = dp(ac+1,r);
	if(a[ac]<=r)me[ac][r] = (me[ac][r] + dp(ac+1,r-a[ac]))%MOD;
	return me[ac][r];
}

int main(){
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin>>n>>s;
	for(int i=0;i<n;i++)cin>>a[i];
	long long res = 0,i;
	memset(me,-1,sizeof me);
	for(i=0;i<n;i++)if(a[i]<=s){
		res = (res + (i+1)*dp(i+1,s-a[i]))%MOD;
	}
	cout<<res<<endl;
	
	return 0;
}
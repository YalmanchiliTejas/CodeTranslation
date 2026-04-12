#include <iostream>

using namespace std;

long long en[200000],me[200000][2];
int vi[200000][2];
int n;

long long dp(int ac, int v){
	if(ac<0)return 0;
	if(vi[ac][v])return me[ac][v];
	vi[ac][v]=1;
	if(v)return me[ac][v] = en[ac] + dp(ac-2,v);
	if(ac%2){
		return me[ac][v] = max(dp(ac-1,1), en[ac] + dp(ac-2,v));
	}
	if(ac==0)return me[ac][v]=0;
	
	return me[ac][v] = max(dp(ac-1,v),en[ac] + dp(ac-2,v));
}
int main(){
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>en[i];
	}
	cout<<dp(n-1,0);
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pn[51],bn[51];

ll solve(ll n,ll x){
	if(n==0)return x;
	else if(x<=1)return 0;
	else if(x<=1+bn[n-1])return solve(n-1,x-1);
	else if(x==bn[n-1]+2)return pn[n-1]+1;
	else if(x<=bn[n]-1)return pn[n-1]+1+solve(n-1,x-2-bn[n-1]);
	else return pn[n];
}

int main(){
	ll n,x;
	cin>>n>>x;
	pn[0]=1;bn[0]=1;
	for(int i=0;i<50;i++){
		pn[i+1]=1+2*pn[i];
		bn[i+1]=3+2*bn[i];
	}

	cout<<solve(n,x)<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mx=100010;
int sp[mx][35];
ll cum[mx][35];
int main(){
	ll n,x,m;
	cin>>n>>x>>m;
	for(int i=0;i<m;i++){
		sp[i][0]=(i*1LL*i)%m;
		cum[i][0]=sp[i][0];
	}
	for(int j=1;j<35;j++){
		for(int i=0;i<m;i++){
			sp[i][j]=i;
			cum[i][j]+=cum[sp[i][j]][j-1];
			sp[i][j]=sp[sp[i][j]][j-1];

			cum[i][j]+=cum[sp[i][j]][j-1];
			sp[i][j]=sp[sp[i][j]][j-1];
		}
	}
	ll curr=x,an=x;
	for(int i=35;i>=0;i--){
		if((n-1)&(1LL<<i)){
			an+=cum[curr][i];
			curr=sp[curr][i];
		}
	}
	cout<<an<<endl;
}
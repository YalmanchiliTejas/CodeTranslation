#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<set>
#include<math.h>
using namespace std;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

#define rep(i,x) for(int i=0;i<x;i++)
#define re(i,x,y) for(int i=x;i<y;i++)

long long INF=1e9;
const int mod=10007;
#define ll long long

ll f[51]={1};
ll p[51]={1};
ll patty(int n,ll x){
	if(x>=f[n]-1)return p[n];
	if(x<=1)return 0;
	if(x<=f[n-1]+1)return patty(n-1,x-1);
	if(x<=f[n-1]+2)return p[n-1]+1;
	if(x<=f[n]-1)return p[n-1]+1+patty(n-1,x-f[n-1]-2);
}

int main(){
	int n;
	ll x;
	cin>>n>>x;
	for(int i=1;i<51;i++){
		f[i]=2*f[i-1]+3;
		p[i]=2*p[i-1]+1;
	}
	cout<<patty(n,x);
	return 0;
}

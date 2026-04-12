#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*

*/

ll n,x,h[100],p[100];

ll f(ll d,ll l){
	if(d==0)return 0;
	if(l==0)return 1;
	ll ans=0;
	if(d-2>=h[l-1]*2){
		ans+=p[l];
	}else if(d-1>=h[l-1]){
		ans+=p[l-1];
		if(d-2>=h[l-1]){
			ans++;
			ans+=f(d-h[l-1]-2,l-1);
		}
	}else{
		ans+=f(d-1,l-1);
	}
	return ans;
}

int main(void){
	h[0]=1;
	p[0]=1;
	reg(i,1,50){
		h[i]=2*h[i-1]+3;
		p[i]=2*p[i-1]+1;
	}
	cin>>n>>x;
	cout<<f(x,n)<<endl;
	return 0;
}
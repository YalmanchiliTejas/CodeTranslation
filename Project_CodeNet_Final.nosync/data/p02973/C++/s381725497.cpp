#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0; i<(N); i++)
typedef long long ll;
const ll mod=1e9+7;

ll N;
ll A[100005];
ll a[100005],b[100005];
ll ans;

int main(){ 

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;

rep(i,N){
	cin>>A[i];
}
ans++;
ll n=0;
//a[n]=A[0]; 
b[n]=-A[0];
n++;

rep(i,N){
	if(i==0) continue;
	ll in=upper_bound(b,b+n,-A[i])-b;
	if(in==0){
		//a[in]=A[i];
		b[in]=-A[i]; 
	}else if(in==n){
		//a[in]=A[i]; 
		b[in]=-A[i];
		ans++;
		n++;
	}
	else{
		//a[in+1]=A[i];
		b[in]=-A[i];
	}
}

cout<<ans<<endl;

}

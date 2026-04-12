#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
#define PP pair<P,int>
#define F first
#define S second
#define f(i,n) for(int i=0;i<(n);i++)
#define INF LLONG_MAX/3
#define eps LDBL_EPSILON
#define mod (int)(1000000007)
#define pie 3.141592653589793238462643383279
#define Bpri priority_queue
#define Spri priority_queue<P,vector<P>,greater<P>>
using namespace std;
int x[100010];
int dat[500000];
bool used[100010];
void update(int i,int a,int b,int l,int r,int z){
	if(a<=l&&b>=r){
		dat[i]+=z;
		return ;
	}
	if(r<=a||b<=l) return ;
	update(i*2+1,a,b,l,(l+r)/2,z);
	update(i*2+2,a,b,(l+r)/2,r,z);
	dat[i]=max(dat[i*2+1],dat[i*2+2]);
}
int qe(int i,int a,int l,int r,int z){
	if(a<l&&r-l==1&&dat[i]>z&&!used[l]){
		used[l]=true;
		dat[i]=-1;
		return l;
	}
	if(r-l==1) return INF;
	if(dat[i*2+1]>z&&(r+l)/2>a+1){
		int bo=qe(i*2+1,a,l,(l+r)/2,z);
		if(bo==INF&&dat[i*2+2]>z)bo=qe(i*2+2,a,(l+r)/2,r,z);
		dat[i]=max(dat[i*2+1],dat[i*2+2]);
		return bo;
	}
	if(dat[i*2+2]>z){
		int bo=qe(i*2+2,a,(l+r)/2,r,z);
		dat[i]=max(dat[i*2+1],dat[i*2+2]);
		return bo;
	}
	return INF;
}
signed main(){
	int n,ans=0;
	cin>>n;
	f(i,n){
		cin>>x[i];
		update(0,i,i+1,0,n,x[i]);
	}
	f(i,n){
		if(!used[i]){
			used[i]=true;
			int z=qe(0,i,0,n,x[i]);
			while(z!=INF){
				z=qe(0,z,0,n,x[z]);
			}
			ans++;
		}
	}
	cout<<ans<<endl;
}

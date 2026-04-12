#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int bit[400000];

void add(int k,int x){
	while(k<400000){
		bit[k]+=x;
		k+=k&-k;
	}
}
int sum(int k){
	int res=0;
	while(k){
		res+=bit[k];
		k-=k&-k;
	}
	return res;
}
int a[200000];

signed main(){
	int n;scanf("%d",&n);
	vector<int>v;
	rep(i,n){
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	rep(i,n){
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
		add(a[i],1);
	}
	rep(i,n){
		add(a[i],-1);
		int l=0,r=400000;
		int A=n/2;
		while(l!=r){
			int t=(l+r)/2;
			if(sum(t)>=A)r=t;
			else l=t+1;
		}
		printf("%d\n",v[l-1]);
		add(a[i],1);
	}
}
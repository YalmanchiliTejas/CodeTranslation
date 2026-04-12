#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tree<P,null_type,less<P>,rb_tree_tag,tree_order_statistics_node_update>tr;


int a[200000];

signed main(){
	int n;scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
		tr.insert(P(a[i],i));
	}
	rep(i,n){
		tr.erase(P(a[i],i));
		int l=0,r=1000000000;
		int A=n/2;
		while(l!=r){
			int t=(l+r)/2;
			if(tr.order_of_key(P(t,INT_MAX))>=A)r=t;
			else l=t+1;
		}
		printf("%d\n",l);
		tr.insert(P(a[i],i));
	}
}
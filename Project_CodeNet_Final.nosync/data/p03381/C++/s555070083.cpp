#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef pair<int,int>P;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tree<pair<int,int>,null_type,less<pair<int,int>>,splay_tree_tag,tree_order_statistics_node_update>tr;

int a[200000];
int main(){
	int n;scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
		tr.insert(P(a[i],i));
	}
	rep(i,n){
		tr.erase(P(a[i],i));
		printf("%d\n",tr.find_by_order((n-1)/2)->first);
		tr.insert(P(a[i],i));
	}
}
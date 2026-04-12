#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int x[200010],sorted[200010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",x+i);
		sorted[i]=x[i];
	}
	sort(sorted+1,sorted+1+n);
	for(int i=1;i<=n;i++){
		int pos=lower_bound(sorted+1,sorted+1+n,x[i])-sorted;
		if(pos<=(n>>1)) printf("%d\n",sorted[(n>>1)+1]);
		else printf("%d\n",sorted[n>>1]);
	}
	return 0;
}
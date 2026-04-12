#include<bits/stdc++.h>
#define M 100005
using namespace std;
int n,A[M];
multiset<int>S;
multiset<int>::iterator it;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		it=S.lower_bound(A[i]);
		if(S.size()&&it!=S.begin())S.erase(--it);
		else ans++;
		S.insert(A[i]);
	}
	printf("%d\n",ans);
	return 0;
}
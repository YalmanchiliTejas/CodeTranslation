#include<bits/stdc++.h>
#define M 100005
using namespace std;
int n,A[M];
multiset<int>s;
multiset<int>::iterator it;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		it=s.lower_bound(A[i]);
		if(s.size()&&it!=s.begin())s.erase(--it);
		else ans++;
		s.insert(A[i]);
	}
	cout<<ans<<endl;
	return 0;
}
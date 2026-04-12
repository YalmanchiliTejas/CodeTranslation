#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;

int n,A[M];

multiset<int>S;
typedef multiset<int>::iterator sit;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(S.size() and *S.begin()<A[i])S.erase(--S.upper_bound(A[i]-1));
		else ans++;
		S.insert(A[i]);
	}
	printf("%d\n",ans);
	return 0;
}
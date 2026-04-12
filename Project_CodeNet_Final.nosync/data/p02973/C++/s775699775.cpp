#include<bits/stdc++.h>
#define N 200005
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;
multiset<int>st;
multiset<int>::iterator it;
int n,m;
bool res;
int A[N];
int ans;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&A[i]);}
	for(int i=n;i;i--){
		it=st.upper_bound(A[i]);
		if(it==st.end())ans++,st.insert(A[i]);
		else st.erase(it),st.insert(A[i]);
	}
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
multiset<int>st;
multiset<int>::iterator it;
int n,A[M];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&A[i]);
	}
	for(int i=n; i>=1; i--){
		it=st.upper_bound(A[i]);
		if(it!=st.end()) st.erase(it);
		st.insert(A[i]);
	}
	printf("%d\n",st.size());
	return 0;
}
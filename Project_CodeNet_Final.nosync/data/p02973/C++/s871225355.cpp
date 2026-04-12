#include<bits/stdc++.h>
#define M 100002
using namespace std;
int A[M];
multiset<int>Q;
multiset<int>::iterator it;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=n;i++){
		if(Q.empty())Q.insert(A[i]);
		else {
			it=Q.lower_bound(A[i]);
			if(it==Q.begin()){
				Q.insert(A[i]);
				continue;
			}
			it--;
			Q.erase(it);
			Q.insert(A[i]);
		}
	}
	printf("%d\n",Q.size());
	return 0;
}
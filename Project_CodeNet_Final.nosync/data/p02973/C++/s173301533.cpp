#include<bits/stdc++.h>
using namespace std;
multiset<int>S;
multiset<int>::iterator it;
int A[100001];
int main() {
	int a,i,w=0;
	cin>>a;
	for(i=1;i<=a;i++)cin>>A[i];
	for(i=a;i;i--){
		it=S.upper_bound(A[i]);
		if(it!=S.end())S.erase(it),w++;
		S.insert(A[i]);
	}
	cout<<a-w;
}
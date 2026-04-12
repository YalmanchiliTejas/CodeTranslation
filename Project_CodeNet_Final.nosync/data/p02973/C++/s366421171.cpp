#include<bits/stdc++.h>
using namespace std;
const int M=100001;
int n,A[M],ans;
multiset<int>s;
multiset<int>::iterator it;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=n;i++){
		if(!s.size()){
			s.insert(A[i]);
			ans++;
			continue;
		}
		it=s.lower_bound(A[i]);
		if(it==s.begin()){
			s.insert(A[i]);
			ans++;
		}else{
			it--;
			s.erase(it);
			s.insert(A[i]);
		}
	}
	printf("%d\n",ans);
}
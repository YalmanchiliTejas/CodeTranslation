#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,K;
int in[N];
multiset<int>S;
multiset<int>::iterator it;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&in[i]);
		it=S.lower_bound(in[i]);
		if(it==S.begin()){
			S.insert(in[i]);
		}else{
			it--;
			int x=*it;
			S.erase(it);
			S.insert(in[i]);
		}
	}
	printf("%d\n",S.size());
}
int main(){
	solve();
	return 0;
}
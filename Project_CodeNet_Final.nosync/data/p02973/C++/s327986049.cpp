#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p=998244353ll;
const int N=200005;
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
multiset<int>S;
int main(){
	int n,i,a;multiset<int>::iterator it;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a);
		if((it=S.lower_bound(a))!=S.begin())S.erase(--it);
		S.insert(a);
	}
	printf("%d",S.size());
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,ans,a;
multiset<int>st;
multiset<int>:: iterator it;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
		if(st.empty()||a<=*st.begin())ans++;
		else {
			it=st.lower_bound(a);
			it--;
			st.erase(it);
		}st.insert(a);
	}
	printf("%d\n",ans);
}
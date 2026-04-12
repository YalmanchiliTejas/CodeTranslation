#include<bits/stdc++.h>
using namespace std;
#define M 100005
int a[M];
multiset<int>q;
multiset<int>::iterator it;
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		if(!q.size())ans++,q.insert(a[i]);
		else{
			if(*q.begin()>=a[i]){
				q.insert(a[i]);
				ans++;
			}
			else{
				it=q.lower_bound(a[i]);
				it--;q.erase(q.find(*it));
				q.insert(a[i]);
			}
		}
	}
	printf("%d",ans);
}
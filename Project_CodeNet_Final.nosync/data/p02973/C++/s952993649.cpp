#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int a[200010];
multiset<int>s;
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",a+i);
	s.insert(a[1]);
	for(int i=2;i<=n;i++){
		if(a[i]<=*s.begin())s.insert(a[i]);
		else {
			s.insert(a[i]);
			auto x=s.lower_bound(a[i]);
			while(*x==a[i])x--;
			s.erase(x);
		}
	}
	printf("%d\n",s.size());
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N];
multiset<int> S;

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	S.clear();
	for (int i=1;i<=n;i++) {
		auto it=S.lower_bound(a[i]);  //查找第一个大于等于a[i]的值 
		if (it!=S.begin()) S.erase(--it);  //(--it)就是小于a[i]且最大的值，a[i]将会替换它 
		S.insert(a[i]);
	}
	cout<<S.size()<<endl;
	return 0;
}
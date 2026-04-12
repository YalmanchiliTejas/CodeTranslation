#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,ans,now;
struct V {
	int k,num;
	bool operator <(const V a)const {
		if(k^a.k)return k>a.k;
		return num<a.num;
	}
} A[N];
set<int>S;
set<int>::iterator fo;
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&A[i].k),A[i].num=i;
	sort(A+1,A+n+1);
	for(int i=1; i<=n; i++) {
		fo=S.lower_bound(A[i].num);
		if(fo==S.end())ans++;
		else S.erase(fo);
		S.insert(A[i].num);
	}
	printf("%d",ans);
	return 0;
}
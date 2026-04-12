#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
const int mx = 100005;
int n, m, a[mx], b[mx];
vector<int> ans;
int main(){
	scanf("%d", &n);
	rep(i,n) scanf("%d", a+i);
	auto J = [&]{
		int v[mx];
		rep(i,m+1) v[i] = -1;
		rep(i,n){
			auto t = lower_bound(v,v+m,a[i]);
			if(t != v) v[t-v-1] = a[i];
			else return true;
		}
		return false;
	};
	for(int l=0,r=n;(m=(l+r)/2)>l;(J()?l:r)=m);
	printf("%d\n", m+1);
}
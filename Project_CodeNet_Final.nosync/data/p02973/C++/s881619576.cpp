#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;
const int INF = 1e9+7;
int n, a[MX], b[MX];
int main(){
	scanf("%d", &n);
	fill(b,b+n+1,INF);
	rep(i,n) scanf("%d", a+n-1-i);
	rep(i,n) *upper_bound(b,b+n,a[i]) = a[i];
	rep(i,n+1) if(b[i]==INF) return 0*printf("%d\n",i);
}
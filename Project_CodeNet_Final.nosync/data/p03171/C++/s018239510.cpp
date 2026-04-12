#include <bits/stdc++.h>
using namespace std;

#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define per(i,n) for (int i=(int)(n)-1;i>=0;i--)
#define For(i,n) for (int i=1;i<=(int)(n);i++)
#define Rep(i,n) for (int i=0;i<=(int)(n);i++)
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define pii pair<int,int>
#define vi vector <int>
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define re return
#define se second
#define fi first
const int INF=0x7fffffff;
const int MAXN=3000+3;

ll f[MAXN][MAXN],a[MAXN],n;
bool v[MAXN][MAXN];

ll dfs(const int &l,const int &r){
	if (v[l][r]) re f[l][r];
	if (l==r-1) re a[l];
	v[l][r]=1;
	f[l][r]=max(a[l]-dfs(l+1,r),a[r-1]-dfs(l,r-1));
	re f[l][r];
}

int main(){
	cin>>n;
	rep(i,n){
		cin>>a[i];
	}
	cout<<dfs(0,n)<<endl;
	re 0;
}
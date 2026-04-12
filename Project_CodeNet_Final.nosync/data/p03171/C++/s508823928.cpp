#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<deque>
#define ll long long
using namespace std;
#define BUF_SIZE 1048576
char _buf[BUF_SIZE],*_is=_buf,*_it=_buf;
inline char rdc(){
	if (_is==_it) _it=(_is=_buf)+fread(_buf,1,BUF_SIZE,stdin);
	return *_is++;
}
inline int rdi(){
	int x=0,f=0;
	register char ch=rdc();
	while ((ch<'0' or ch>'9') and (ch^'-')) ch=rdc();
	if (ch=='-') f=1,ch=rdc();
	while (ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch^'0'),ch=rdc();
	return f?-x:x;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void _write(int x){
	write(x);
	putchar(' ');
}
inline void print(int x){
	write(x);
	putchar('\n');
}
#define int long long
const int N=3005;
int dp[N][N];
bool use[N][N];
int a[N];
inline int solve(int l,int r){
	if(l>r) return 0;
	if(use[l][r]) return dp[l][r];
	use[l][r]=1;
	int res=-1234325326153125;
	res=max(res,a[l]-solve(l+1,r));
	res=max(res,a[r]-solve(l,r-1));
	dp[l][r]=res;
	return res;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,i;
	cin>>n;
	for(i=1;i<=n;++i) cin>>a[i];
	solve(1,n);
	cout<<dp[1][n]<<endl;
	return 0;
}

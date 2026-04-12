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
inline void rdi(int &x){
	int f=0;
	register char ch=rdc();
	while ((ch<'0' or ch>'9') and (ch^'-')) ch=rdc();
	if (ch=='-') f=1,ch=rdc();
	while (ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch^'0'),ch=rdc();
	if(f) x=-x;
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
ll to[1<<19],pr[1<<19];
int n,m;
vector<pair<int,ll> >v[1<<18];
inline void upd(int a,int b,ll V,int lo=0,int hi=1<<18,int x=1){
	if(b<=lo or a>=hi) return;
	if(a<=lo and hi<=b){
		to[x]+=V;
		pr[x]+=V;
		return;
	}
	int md=(lo+hi)>>1;
	upd(a,b,V,lo,md,x*2);
	upd(a,b,V,md,hi,x*2+1);
	to[x]=max(to[x*2],to[x*2+1])+pr[x];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		v[b-1].push_back(make_pair(a-1,c));
	}
	for(int i=0;i<n;++i){
		upd(i,i+1,to[1]);
		for(auto t:v[i]) upd(t.first,i+1,t.second);
	}
	cout<<to[1]<<endl;
	return 0;
}
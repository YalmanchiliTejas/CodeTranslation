/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n;
int s[505],t[505];
unsigned long long u[505],v[505],ans[505][505];
unsigned long long mat[505][505];
void check_all(){
	for(int i=1;i<=n;i++){
		unsigned long long cur=0;
		if(s[i]==0)cur=~cur;
		for(int j=1;j<=n;j++){
			(s[i]==0?cur&=ans[i][j]:cur|=ans[i][j]);
		}
		if(cur!=u[i]){
			puts("-1");
			exit(0);
		}
	}
	for(int j=1;j<=n;j++){
		unsigned long long cur=0;
		if(t[j]==0)cur=~cur;
		for(int i=1;i<=n;i++){
			(t[j]==0?cur&=ans[i][j]:cur|=ans[i][j]);
		}
		if(cur!=v[j]){
			puts("-1");
			exit(0);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=1;i<=n;i++)cin>>u[i];
	for(int i=1;i<=n;i++)cin>>v[i];
	if(n==1){
		if(u[1]!=v[1]){
			puts("-1");
		}else{
			cout<<u[1]<<endl;
		}
		return 0;
	}
	for(int bit=0;bit<64;bit++){
		memset(mat,-1,sizeof mat);
		vector<int>r,c;
		bool z=0,o=0;
		int R=-1,C=-1;
		for(int i=1;i<=n;i++){
			int val=(u[i]>>bit)&1;
			if(s[i]==0){
				if(val==1)for(int j=1;j<=n;j++)mat[i][j]=1,o=1,R=1;
				else r.push_back(i);
			}else{
				if(val==0)for(int j=1;j<=n;j++)mat[i][j]=0,z=1,R=0;
				else r.push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			int val=(v[i]>>bit)&1;
			if(t[i]==0){
				if(val==1)for(int j=1;j<=n;j++)mat[j][i]=1,o=1,C=1;
				else c.push_back(i);
			}else{
				if(val==0)for(int j=1;j<=n;j++)mat[j][i]=0,z=1,C=0;
				else c.push_back(i);
			}
		}
		if(r.size()==1){
			int x=r[0];
			for(auto y:c){
				if(R==(v[y]>>bit)%2)mat[x][y]=(u[x]>>bit)%2;
				else mat[x][y]=(v[y]>>bit)%2;
			}
		}else if(c.size()==1){
			int y=c[0]; 
			for(auto x:r){
				if(C==(u[x]>>bit)%2)mat[x][y]=(v[y]>>bit)%2;
				else mat[x][y]=(u[x]>>bit)%2;
			}
		}else{
			int t=0,tt=0;
			for(int i=0;i<r.size();i++){
				for(int j=0;j<c.size();j++){
					mat[r[i]][c[j]]=(i+j)%2;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
//				cerr<<mat[i][j]<<" ";
				ans[i][j]|=((mat[i][j]?1ull:0ull)<<bit);
			}
//			cerr<<endl;
		}
	}
	check_all();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
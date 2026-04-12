#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define qwq(x) cerr<<" #"<<#x<<" = "<<x<<endl;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1000005;
int f[20][20],n,m;
char s[20][20];

int L(int x,int y){
	int res=0;
	rep(i,1,y)
		if(s[x][i]=='#')res++;
	return res;
}

int U(int x,int y){
	int res=0;
	rep(i,1,x)
		if(s[i][y]=='#')res++;
	return res;
}

int main(){
	read(n),read(m);
	rep(i,1,n)scanf("%s",s[i]+1);
	f[1][1]=1;
	rep(i,1,n)rep(j,1,m)
		if(i+j>=2){
			if(f[i-1][j]&&L(i,j-1)==0)
				f[i][j]=1;
			if(f[i][j-1]&&U(i-1,j)==0)
				f[i][j]=1;
		}
	if(f[n][m])puts("Possible");
	else puts("Impossible");
	return 0;
}

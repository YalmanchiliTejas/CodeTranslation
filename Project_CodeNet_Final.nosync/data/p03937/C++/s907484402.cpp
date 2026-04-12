#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define iter(v,ite) for(auto ite=(v).begin();ite!=(v).end();ite++)
#define mimunum(v,x) distance((v).begin(),lower_bound((v).begin(),(v).end(),x))

char s[15][15]={};
int h,w;
bool dfs(int y,int x){
	if(y>=h || x>=w)return false;
	if(s[y][x]!='#')return false;
	s[y][x]='@';
	bool res=true;
	if(y+1==h && x+1==w){
		rep(y,h)rep(x,w){
			if(s[y][x]=='#')res=false;
		}
	}
	else{
		res = (dfs(y+1,x) || dfs(y,x+1));
	}
	s[y][x]='#';
	return res;
}

int main(void){
	scanf("%d%d",&h,&w);
	rep(y,h)scanf("%s",s[y]);
	printf("%s\n",dfs(0,0)?"Possible":"Impossible");
	return 0;
}





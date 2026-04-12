#include<map>
#include<stack>
#include<deque>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include<algorithm>
#define inf 1e9
#define re register
#define ll long long
#define Flj(i,a,b) for(int i=(a);i;i=(b))
#define Fze(i,a,b) for(int i=(a);i<(b);i++)
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Fer(i,a,b) for(int i=(a);i>=(b);i--)
#define Fer1(i,a,b) for(int i=(a);i>b;i--)
#define Dfor(i,a,b,k) for(double i=(a);i<(b);i+=k)
#define Qmax priority_queue
#define Qmin priority_queue<int,vector<int>,greater<int> >
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int x;
int main(){
	x=read();
	if(x==3||x==5||x==7)printf("YES");
	else printf("NO");
} 
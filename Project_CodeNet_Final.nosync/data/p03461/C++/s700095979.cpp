#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=310,M=100010;
bool w[N][N];
int s1[N],s2[N];
struct Dat {
    int x,y,z;
} g[N],v[M];
inline int gi() {
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x;
}
int main() {
    int A,B,cnt=0,n=0,m=0;
    cin>>A>>B;
    for(int i=0;i<=100;i++) {
	s1[i]=++n,s2[i]=++n;
	if(i) {
	    v[++m]=(Dat){s1[i-1],s1[i],-1};
	    v[++m]=(Dat){s2[i],s2[i-1],-2};
	}
    }
    for(int i=1;i<=A;i++)
	for(int j=1;j<=B;j++) g[++cnt]=(Dat){i,j,gi()};
    for(int i=1;i<=cnt;i++) {
	int x=g[i].x,y=g[i].y,z=g[i].z;
	for(int p=0;p*x<=z;p++)
	    for(int q=0;p*x+q*y<=z;q++) {
		int c=z-p*x-q*y;
		bool flg=1;
		for(int j=1;j<=cnt;j++) {
		    int X=g[j].x,Y=g[j].y;
		    if(p*X+q*Y+c<g[j].z) {flg=0;break;}
		}
		if(flg) {
		    if(!w[s1[p]][s2[q]])
			w[s1[p]][s2[q]]=1,v[++m]=(Dat){s1[p],s2[q],c};
		    goto ed;
		}
	    }
	return puts("Impossible"),0;
    ed:;
    }
    puts("Possible");
    cout<<n<<' '<<m<<endl;
    for(int i=1;i<=m;i++) {
	printf("%d %d ",v[i].x,v[i].y);
	if(v[i].z==-1) puts("X");
	else if(v[i].z==-2) puts("Y");
	else printf("%d\n",v[i].z);
    }
    cout<<1<<' '<<2;
    return 0;
}
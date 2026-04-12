#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=200010;
int a[N],id[N],ans[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline bool cmp(const int &x,const int &y) {return a[x]<a[y];}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=gi(),id[i]=i;
    sort(id+1,id+1+n,cmp);
    for(int i=1;i<=n;i++) {
	int t=id[i];
	if(i+i<=n) ans[t]=a[id[n/2+1]];
	else ans[t]=a[id[n/2]];
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
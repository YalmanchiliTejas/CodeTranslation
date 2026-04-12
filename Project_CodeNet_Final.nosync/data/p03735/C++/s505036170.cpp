#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=200010;
int a[N],b[N],id[N];
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
    int n,A=1<<30,B=0,C=1<<30,D=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
	a[i]=gi(),b[i]=gi(),id[i]=i;
	if(a[i]>b[i]) swap(a[i],b[i]);
    }
    for(int i=1;i<=n;i++) {
	A=min(A,a[i]),B=max(B,a[i]);
	C=min(C,b[i]),D=max(D,b[i]);
    }
    long long ans=1LL*(B-A)*(D-C);
    A=max(B,D)-min(A,C);
    sort(id+1,id+1+n,cmp);
    a[0]=C=1<<30,D=a[id[n]];
    for(int i=1;i<=n;i++) {
	C=min(C,b[id[i]]),D=max(D,b[id[i]]);;
	ans=min(ans,1LL*A*(D-min(C,a[id[i+1]])));
    }
    cout<<ans;
    return 0;
}
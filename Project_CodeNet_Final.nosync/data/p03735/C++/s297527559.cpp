#include<bits/stdc++.h>
using namespace std;

#define int long long 

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}
 
void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

const int maxn = 2e5+10;
const int inf = 1e9;
const lf eps = 1e-8;

int mx,mn=1e9,n,mn1=1e9,mx1;
struct data{
    int x,y;
    bool operator < (const data &rhs) const {return x<rhs.x;}
}a[maxn];

signed main() {
    read(n);
    for(int i=1;i<=n;i++) {
        read(a[i].x),read(a[i].y);if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
        mx=max(mx,a[i].y),mn=min(mn,a[i].x);
        mn1=min(mn1,a[i].y),mx1=max(mx1,a[i].x);
    }sort(a+1,a+n+1);
    int ans=(mx-mn1)*(mx1-mn),res,mn2=a[1].y,mx2=a[1].y;
    res=max(a[1].y,a[n].x)-min(a[1].y,a[2].x);
    for(int i=2;i<=n;i++) {
        mn2=min(mn2,a[i].y),mx2=max(mx2,a[i].y);
        if(i!=n) res=min(res,max(mx2,a[n].x)-min(mn2,a[i+1].x));
    }ans=min(ans,res*(mx-mn));
    write(ans);
    return 0;
}

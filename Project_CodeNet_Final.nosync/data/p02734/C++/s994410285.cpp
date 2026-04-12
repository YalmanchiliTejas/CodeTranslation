#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e3+5;
const int MD=998244353;
int a[N],f[N];
void add(int &x,int y) {
    x+=y;
    if(x>=MD) x-=MD;
}
int main() {
    //freopen("in.txt","r",stdin);
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        add(f[0],1);
        for(int j=s;j>=a[i];j--) {
            add(f[j],f[j-a[i]]);
        }
        add(ans,f[s]);
    }
    printf("%d\n",ans);
    return 0;
}
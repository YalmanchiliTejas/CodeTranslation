#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll arr[400100];
int ord[400100];
int rrd[400100];
int col[400100];
ll maxi[400100];

bool cmp(int a, int b) {return arr[a]<arr[b];}

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld%lld",&arr[i*2],&arr[i*2+1]);
    for (i=0;i<2*n;i++) ord[i] = i;
    sort(ord,ord+2*n,cmp);
    for (i=0;i<2*n;i++) rrd[ord[i]] = i;
    maxi[0] = 987654321;
    for (i=1;i<2*n;i++) {
        maxi[i] = maxi[i-1];
        if (rrd[ord[i-1]]>rrd[ord[i-1]^1]) continue;
        maxi[i] = min(maxi[i],1LL*rrd[ord[i-1]^1]);
    }
    //for (i=0;i<2*n;i++) printf("%lld ",maxi[i]);
    ll res = 1LL<<60;
    ll mi = rrd[ord[2*n-1]^1];
    for (i=2*n-1;i>0;i--) {
        if (!mi) break;
        if (col[ord[i]]) break;
        res = min(res,((arr[ord[2*n-1]]-arr[ord[0]])*(arr[ord[i-1]]-arr[ord[min(mi,maxi[mi])]])));
        col[ord[i]] = 1;
        col[ord[i]^1] = 2;
        mi = min(mi,1LL*rrd[ord[i-1]^1]);
    }

    for (i=0;i<2*n;i++) col[i] = 0;
    for (i=2*n-1;i>=0;i--) {
        if (col[ord[i]]) continue;
        col[ord[i]] = 1;
        col[ord[i]^1] = 2;
    }

    ll B[2] = {1987654321,0}, R[2] = {1987654321,0};
    for (i=0;i<2*n;i++) {
        if (col[i]==1) {
            B[0] = min(B[0],arr[i]);
            B[1] = max(B[1],arr[i]);
        }
        else {
            R[0] = min(R[0],arr[i]);
            R[1] = max(R[1],arr[i]);
        }
    }
    res = min(res,(B[1]-B[0])*(R[1]-R[0]));
    printf("%lld\n",res);

    return 0;
}

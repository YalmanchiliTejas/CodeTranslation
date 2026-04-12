#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 3e5+5;

int A[N];

ll preSum[N];

ll prefix[N],suffix[N];
void solve() {
    int n,k;
    scanf("%d%d",&n,&k);
    ll ret = 0;
    if(k==0) {
        ret = (ll)n*n;
        cout<<ret<<endl;
        return;
    }
    for(int b = k+1;b<=n;++b) {
        for(int a = k;a<=n;a+=b) {
            int t = a;
            int x = b - a%b;
            int lastA = t + x-1;
            lastA = min(n,lastA);
            if(t<=lastA) {
                ret += lastA-t+1;
            }
        }
    }
    printf("%lld\n", ret);
}
int main() {
   //freopen("input.txt","r",stdin);
   solve();
}

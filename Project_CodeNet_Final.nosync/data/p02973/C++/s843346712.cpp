#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;

int n,m;
int ar[maxn];
int mid[maxn];

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", ar+i);
    }
    int be = maxn-1, en = maxn-1, ans=0;
    for(int i=1;i<=n;i++){
        int now = ar[i];
        int k = lower_bound(mid+be, mid+en, now)-mid;
        assert(k>=be && k<=en);
        if(k==be){
            mid[--be] = now;
            ans++;
        }
        else{
            k--;
            mid[k] = now;
        }
    }
    printf("%d\n", ans);


    return 0;
}

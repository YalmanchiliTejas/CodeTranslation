#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
using namespace std;
long long ans,pre;
const int mod = 1e9+7;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n,t;
    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        scanf("%d",&t);
        ans = (ans + (pre*t))%mod;
        pre = (pre+t)%mod;
    }
    printf("%d\n",ans);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

const int MOD   = 1e9+7;
const int MAXN  = 1010;


int main() {
#ifdef LOCAL
    freopen("sample.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    int ans=a*100+b*10+c;
    if(ans%4)
        cout<<"NO"<<endl;
    else 
        cout<<"YES"<<endl;

    return 0;
}


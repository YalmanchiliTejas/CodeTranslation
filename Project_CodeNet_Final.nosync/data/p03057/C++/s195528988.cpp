#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod=1e9+7;

void U(int &x,int y){
    x=(x+y)%mod;
}

int n, m, a[202000];
char s[202000];

int main(){
    cin>>n>>m>>s+1;
    for (int i=1;i<=m;++i)
        a[i]= s[i]==s[1];
    if (*min_element(a+1,a+m+1)==1){
        static int f[202000][2][2];
        f[1][0][0]=f[1][1][1]=1;
        for (int i=1;i<n;++i){
            for (int s=0;s<=1;++s)
                for (int t=0;t<=1;++t)
                    for (int tt=0;tt<=1;++tt){
                        if (t==0&&tt==0) continue;
                        U(f[i+1][s][tt],f[i][s][t]);
                    }
        }
        int ans=(1ll*f[n][0][1]+f[n][1][0]+f[n][1][1])%mod;
        cout<<ans<<endl;
        return 0;
    }
    int las=0, mx=1e9; vector<int>vec;
    for (int i=1;i<=m;++i)
        if (a[i]){
            ++las;
        }else{
            vec.push_back(las);
            las=0;
        }
    {
        int t=vec.front(); vec.erase(vec.begin());
        mx=min(mx,(t&1? t: t+1));
    }
    for (auto t:vec){
        if (t&1) mx=min(mx,t);
    }


    static int ans=0, f[202000], sum[202000];
    f[1]=sum[1]=1;
    for (int i=1;i<=n;++i){
        if (i!=1){
            f[i]=(sum[i-2]-sum[max(0,i-mx-3)]+mod)%mod;
            sum[i]=(sum[i-2]+f[i])%mod;
        }
        if ((n-i&1)&&n-i<=mx){
            ans=(ans+(ll)f[i]*(n-i+1))%mod;
        }
    }
    cout<<ans<<endl;
}
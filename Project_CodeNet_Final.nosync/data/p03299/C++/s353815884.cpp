#include<bits/stdc++.h>
using namespace std;

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

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int a[maxn],n;

int qpow(int a,int x) {
    int res=1;
    for(;x;x>>=1,a=1ll*a*a%mod) if(x&1) res=1ll*res*a%mod;
    return res;
}

pii solve(int l,int r) {
    int mn=1e9,pre=l-1,cnt=0;
    for(int i=l;i<=r;i++) mn=min(mn,a[i]);
    pii ans;ans.fr=ans.sc=1;
    for(int i=l;i<=r+1;i++) {
        if(i!=r+1&&a[i]!=mn) continue;cnt++;
        if(pre==i-1) {pre=i;continue;}
        int t=1e9;
        for(int j=pre+1;j<i;j++) t=min(t,a[j]);
        t--;
        pii res=solve(pre+1,i-1);
        res.sc=1ll*res.sc*qpow(2,t-mn)%mod;
        ans.sc=1ll*ans.sc*res.sc%mod;
        ans.fr=1ll*ans.fr*(2ll*res.sc+res.fr)%mod;
        pre=i;
    }
    cnt--;
    ans.sc=2ll*ans.sc%mod;
    ans.fr=1ll*ans.fr*qpow(2,cnt)%mod;
    ans.fr=(ans.fr-ans.sc+mod)%mod;
    // printf("solve :: %d %d ( %d %d ) \n",l,r,ans.fr,ans.sc);
    return ans;
}

int main() {
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    pii ans=solve(1,n);
    int mn=1e9;
    for(int i=1;i<=n;i++) mn=min(mn,a[i]);
    ans.sc=1ll*ans.sc*qpow(2,mn-1)%mod;
    write((ans.fr+ans.sc)%mod);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define re cin>>
#define pr cout<<
#define in(x) scanf("%d",&x)
#define inn(x,y) scanf("%d%d",&x,&y)
#define innn(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

const int N=3e3+5;
const int mod=998244353;

ll sumIndices[N][N];
int n,S,ar[N];

int solve(){
    ll ans=0;
    for(int i=1;i<=n;i++){
        sumIndices[0][i-1]=i;
        for(int j=1;j<=S;j++){
            // SUM OF THE INITIAL INDICES FORMING SUM J FROM 1..I INDEX
            if(j<ar[i]) sumIndices[j][i]=sumIndices[j][i-1];
            else sumIndices[j][i]=(
                sumIndices[j-ar[i]][i-1] // INC J
                +sumIndices[j][i-1] // EXCLUDING J
            )%mod;
        }
        if(ar[i]<=S) ans=ans+(sumIndices[S-ar[i]][i-1])*(n-i+1);
        ans%=mod;
    }
    return ans;
}

int main(){
    re n>>S;
    rep1(i,n) cin>>ar[i];
    pr solve();
    return 0;
}

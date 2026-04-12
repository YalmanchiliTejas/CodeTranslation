#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9;
const long long IINF=1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,W,T; cin >> N >> M >> W >> T;
    vector<string> S(M),comp;
    vector<int> V0(M),L(N),X(N),Y(N),cS(M),V(M);
    vector<ll> P0(M),P(M);
    vector<vector<string>> R(N);
    vector<vector<int>> cR(N);
    vector<vector<ll>> Q(N);
    for (int i=0;i<M;++i){
        cin >> S[i] >> V0[i] >> P0[i];
        comp.emplace_back(S[i]);
    }
    for (int i=0;i<N;++i){
        cin >> L[i] >> X[i] >> Y[i];
        for (int j=0;j<L[i];++j){
            string r; int q; cin >> r >> q;
            R[i].emplace_back(r);
            Q[i].emplace_back(q);
            comp.emplace_back(r);
        }
    }
    X.emplace_back(0); Y.emplace_back(0);
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    for (int i=0;i<M;++i){
        cS[i]=lower_bound(comp.begin(),comp.end(),S[i])-comp.begin();
        V[cS[i]]=V0[i]; P[cS[i]]=P0[i];
    }
    for (int i=0;i<N;++i){
        for (int j=0;j<L[i];++j){
            int cr=lower_bound(comp.begin(),comp.end(),R[i][j])-comp.begin();
            cR[i].emplace_back(cr);
        }
    }
    vector<vector<ll>> dp0(1<<N,vector<ll>(W+1,-IINF));
    vector<vector<int>> dp1(1<<(N+1),vector<int>(N+1,INF));
    auto d=[&](int i,int j){return abs(X[i]-X[j])+abs(Y[i]-Y[j]);};
    dp0[0][0]=dp1[0][N]=0;
    for (int mask=1;mask<(1<<N);++mask){
        int pre=mask,now;
        for (int i=N-1;i>=0;--i) if (mask&1<<i){
            now=i; pre^=1<<i; break;
        }
        for (int j=0;j<=W;++j) dp0[mask][j]=dp0[pre][j];
        for (int j=0;j<=W;++j){
            for (int k=0;k<L[now];++k){
                if (j+V[cR[now][k]]<=W){
                    dp0[mask][j+V[cR[now][k]]]=max(dp0[mask][j+V[cR[now][k]]],dp0[mask][j]+P[cR[now][k]]-Q[now][k]);
                }
            }
        }
    }
    for (int mask=0;mask<(1<<(N+1));++mask){
        for (int i=0;i<=N;++i){
            for (int j=0;j<=N;++j){
                if (!(mask&1<<j)){
                    dp1[mask|1<<j][j]=min(dp1[mask|1<<j][j],dp1[mask][i]+d(i,j));
                }
            }
        }
    }
    vector<pair<ll,int>> v;
    for (int mask=0;mask<(1<<N);++mask){
        ll Max=0;
        for (int j=0;j<=W;++j) Max=max(Max,dp0[mask][j]);
        v.emplace_back(Max,dp1[mask|1<<N][N]);
    }
    vector<ll> dp(T+1,-IINF);
    dp[0]=0;
    for (int i=0;i<=T;++i){
        for (auto p:v){
            ll val=p.first; int t=p.second;
            if (i+t<=T) dp[i+t]=max(dp[i+t],dp[i]+val);
        }
    }
    ll ans=0;
    for (int i=0;i<=T;++i) ans=max(ans,dp[i]);
    cout << ans << '\n';
}


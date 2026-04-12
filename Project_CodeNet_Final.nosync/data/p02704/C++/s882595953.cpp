#include<bits/stdc++.h>
#define p_ pair<int,int>
#define mp make_pair
#define ll long long
#define Ull unsigned long long
#define pb push_back
#define fi first
#define se second
#define show1(a) cout<<#a<<" "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int n,S[505],T[505],R[505][2],C[505][2],t[505][505];
Ull U[505],V[505],ans[505][505];
bool solve()
{
    for(int k=0;k<64;k++){
        memset(t,-1,sizeof(t));
        memset(R,0,sizeof(R));
        memset(C,0,sizeof(C));
        for(int i=1;i<=n;i++){
            int x = (U[i]&1);if(x!=S[i]) for(int j=1;j<=n;j++){
                t[i][j] = x;
            }
        }
        for(int j=1;j<=n;j++){
            int x = (V[j]&1);if(x!=T[j]) for(int i=1;i<=n;i++){
                if(~t[i][j] && t[i][j]!=x) return false;
                t[i][j] = x;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){if(t[i][j]==-1){
                int x = S[i],y = T[j];
                if(x==y) t[i][j] = x;
                else t[i][j] = 0;
            }R[i][t[i][j]]++,C[j][t[i][j]]++;}
        }
        for(int i=1;i<=n;i++){
            if(!(S[i] && (U[i]&1)))continue;
            if(R[i][1]) continue;
            int flag = 0;
            for(int j=1;j<=n;j++){
                if(!T[j] && !(V[j]&1) && C[j][0]>1){
                    t[i][j] = 1;
                    R[i][0]--,C[j][0]--;
                    R[i][1]++,C[j][1]++;
                    flag = 1;break;
                }
            }
            if(!flag) return false;
        }
        for(int j=1;j<=n;j++){
            if(!(T[j] && (V[j]&1)))continue;
            if(C[j][1]) continue;
            int flag = 0;
            for(int i=1;i<=n;i++){
                if(!S[i] && !(U[i]&1) && R[i][0]>1){
                    t[i][j] = 1;
                    R[i][0]--,C[j][0]--;
                    R[i][1]++,C[j][1]++;
                    flag = 1;break;
                }
            }
            if(!flag) return false;
        }
        for(int i = 1; i <= n; i++) {
            if(S[i] == 0 && (U[i] & 1) == 1 && R[i][1] != n) return false;
            if(S[i] == 0 && (U[i] & 1) == 0 && R[i][1] == n) return false;
            if(S[i] == 1 && (U[i] & 1) == 1 && R[i][1] == 0) return false;
            if(S[i] == 1 && (U[i] & 1) == 0 && R[i][1] != 0) return false;
            if(T[i] == 0 && (V[i] & 1) == 1 && C[i][1] != n) return false;
            if(T[i] == 0 && (V[i] & 1) == 0 && C[i][1] == n) return false;
            if(T[i] == 1 && (V[i] & 1) == 1 && C[i][1] == 0) return false;
            if(T[i] == 1 && (V[i] & 1) == 0 && C[i][1] != 0) return false;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(t[i][j]) ans[i][j]|=(1ULL<<k);
        for(int i=1;i<=n;i++) U[i]>>=1,V[i]>>=1;
    }
    return 1;
}
int main()
{
    fastio();
    cin>>n;
    for(int i=1;i<=n;i++) cin>>S[i];
    for(int i=1;i<=n;i++) cin>>T[i];
    for(int i=1;i<=n;i++) cin>>U[i];
    for(int i=1;i<=n;i++) cin>>V[i];
    if(!solve()) cout<<-1<<endl;
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}

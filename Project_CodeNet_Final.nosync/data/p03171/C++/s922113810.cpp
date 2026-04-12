#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
using namespace std;

int N;
ll w[maxn];
ll f[3030][3030]; // = X-Y

ll solve(){
    for(int i = 1;i<=N;i++) f[i][i] = w[i];
    for(int len = 2;len<=N;len++){
        for(int i = 1;i<=N-len+1;i++){
            int j = i+len-1;
            f[i][j] = max(f[i][j],w[i] - f[i+1][j]);
            f[i][j] = max(f[i][j],w[j] - f[i][j-1]);
        }
    }
    return f[1][N];
}

int main(){
    // debug;
    ios;

    cin>>N;
    for(int i = 1;i<=N;i++) cin>>w[i];
    for(int i = 1;i<=N;i++) for(int j = 1;j<=N;j++) f[i][j] = -1e18;
    cout<<solve()<<'\n';
    
    return 0;
}

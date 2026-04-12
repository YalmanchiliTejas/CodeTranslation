#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PB push_back
using namespace std;
typedef pair<int, int> P1;
typedef pair<int, pair<int, int> > P2;
static const int INF = 1ll<<60;
static const int dx[] = { 1, -1, 0, 0, };
static const int dy[] = { 0, 0, 1, -1 };

int N;
int a[55];
int ans;

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>a[i];
    while(1){
        int sum=0;
        int maxmum=-INF;
        for(int i=0;i<N;++i)maxmum=max(maxmum,a[i]);
        if(maxmum<=N-1)break;
        for(int i=0;i<N;++i)sum+=a[i]/N;
        for(int i=0;i<N;++i){
            int cost = sum - (a[i]/N) - (a[i]/N)*N;
            a[i]+=cost;
        }
        ans+=sum;
    }
    cout<<ans<<endl;
}

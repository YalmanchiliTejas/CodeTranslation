#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> edge(N,vector<int>(N));
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--; b--;
        edge[a][b]=1;
        edge[b][a]=1;
    }
    vector<int> ary(N);
    rep(i,N){
        ary[i]=i;
    }
    int ans = 0;
    do{
        if(ary[0]!=0)break;
        bool ok = true;
        for(int ix=1;ix<N;ix++){
            if(edge[ary[ix-1]][ary[ix]]!=1){
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }while(next_permutation(ary.begin(),ary.end()));
    cout << ans << endl;
    return 0;
}
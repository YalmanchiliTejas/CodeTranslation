#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;

void solve(long long N, long long M, std::vector<long long> a, std::vector<long long> b){
    vector<vector<bool>> connected(N+1, vector<bool>(N+1,false));
    rep(i,0,M) {
        connected[a[i]][b[i]] = true;
        connected[b[i]][a[i]] = true;
    }
    vector<int> paths(N);
    rep(i,0,N) paths[i] = i+1;
    int answer = 0;
    do {
        bool valid = true;
        rep(i,0,paths.size()-1) {
            if (!connected[paths[i]][paths[i+1]]) {
                valid = false;
                break;
            }
        }
        if (valid) answer++;
    } while(next_permutation(all(paths)) && paths.front() == 1);
    cout << answer << endl;
}

signed main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    solve(N, M, std::move(a), std::move(b));
    return 0;
}

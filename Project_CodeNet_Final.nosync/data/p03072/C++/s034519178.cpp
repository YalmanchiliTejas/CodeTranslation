#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1e9;
const int MOD = INF+7;
#define rep(i,N) for(int (i)=0;(i)<(N);++(i))
#define rrep(i,N) for(int (i)=(N-1);(i)>0;--i)
#define FOR(i,j,N) for(int (i)=(j);(i)<(N);++(i))
#define put(n) cout<<(n)<<endl;
#define all(v) v.rbegin(),v.rend()
#define MP make_pair
#define pb push_back
using P = pair<int,int>;
//b

signed main(){
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i,N) cin >> H[i];

    int ans = 0;
    for(int i=0;i<N;i++){
        bool ok = true;
        for(int j=0;j<i;j++){
            if(H[j] > H[i]) ok = false;

        }
        ans += ok;
    }

    cout << ans << endl;
}

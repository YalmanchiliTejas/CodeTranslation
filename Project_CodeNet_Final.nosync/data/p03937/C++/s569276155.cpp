#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = INF+7;
const ll LINF = 1e18;
#define rep(i,N) for(int (i)=0;(i)<(N);++(i))
#define rrep(i,N) for(int (i)=(N-1);(i)>0;--i)
#define FOR(i,j,N) for(int (i)=(j);(i)<(N);++(i))
#define put(n) cout<<(n)<<endl;
#define all(v) v.begin(),v.end()
#define MP make_pair
#define pb(n) push_back(n)

int main(){
    int H,W;
    cin >> H >> W;
    vector<int> left,right;
    rep(i,H){
        int r = -1;
        rep(j,W){
            char A; cin >> A;
            if(A == '#'){
                if(r == -1) left.emplace_back(j);
                r = j;
            }
        }
        right.emplace_back(r);
    }

    bool possible = true;
    rep(i,H-1) if(right[i] > left[i+1]) possible = false;

    if(possible) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int N, M;
bool G[8][8];

int main(){
    cin >> N >> M;
    rep(i, N){
        rep(j, N){
            G[i][j] = false;
        }
    }
    rep(i, M){
        int a,b;
        cin >> a >> b;
        G[a-1][b-1] = true;
        G[b-1][a-1] = true;
    }

    vector<int> v;
    set<vector<int>> l;
    rep(i, N){
        v.push_back(i);
    }
    int ans = 0;
    do {
        bool flag = true;
        rep(i, N-1){
            if (!G[v[i+1]][v[i]]) {
                flag = false;
                break;
            }
        }

        if (flag){
            ans++;
        }


    } while (next_permutation(v.begin()+1, v.end()));


    cout << ans << endl;
}
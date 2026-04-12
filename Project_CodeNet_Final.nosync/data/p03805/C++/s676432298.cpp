#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 999999999;
bool pass[9][9];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
        
    REP(i,M){
        int a,b;
        cin >> a >> b;
        pass[a-1][b-1] = true;
        pass[b-1][a-1] = true;
    }
    vector<int> v;
    REP(i,N){
        v.pb(i);
    }
    int ans = 0;
    do{
        bool flag = true;
        REP(i,N-1){
            if(v[0] != 0){
                flag = false;
                break;
            }
            if(!pass[v[i]][v[i+1]]){
                flag = false;
                break;
            }
        }
        if(flag){ans ++;}
    }while(next_permutation(All(v)));
    cout << ans <<"\n";

    return 0;
}
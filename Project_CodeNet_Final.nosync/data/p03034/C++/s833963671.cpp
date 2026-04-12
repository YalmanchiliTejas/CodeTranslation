#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 1e9 + 10;//10^9
ll MOD  = 1000000007;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int main(void){
    int N;
    cin >> N;
    vector<ll> s(N);
    for(int i = 0; i < N; i++) cin >> s[i];
    ll ans = 0;
    
    for(int C = 1; C <= N - 1; C++){
        set<int> visited;
        ll score = 0;
        for(int x = 0;; x++){
            int A = (N - 1) - x * C;
            if(A <= 0 || N <= A) break;
            if(A-C <= 0 || N <= A-C) break;//B =　A - C
            if(x*C == A) break;
            if(visited.count(x*C) || visited.count(A)) break;
            visited.insert(x*C);
            visited.insert(A);
            score += s[x * C];
            score += s[A];
            ans = max(ans, score);
        }
    }
    cout << ans << endl;
    
}


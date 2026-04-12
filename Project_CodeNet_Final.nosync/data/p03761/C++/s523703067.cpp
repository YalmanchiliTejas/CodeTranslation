#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> a(26,INF);

    REP(i,N){
        string s; cin >> s;
        vector<int> b(26,0);
        
        REP(j,s.size()){
            b[s[j]-'a'] ++;
        }
        REP(j,26){
            a[j] = min(a[j], b[j]); 
        }
    }
    for(char c = 'a'; c<='z'; c++){
        REP(i,a[c-'a']) cout << c;
    }
    cout << endl;

    return 0;
}
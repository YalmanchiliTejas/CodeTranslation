#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define in insert
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e9 + 5;
int main(){
    int n, m;
    cin >> n >> m;
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) if(s[j] == '#'){
            v.pb(s);
            break;
        }
    }
    for(int i = 0; i < m; i++){
        bool q = true;
        for(int j = 0; j < v.size(); j++) if(v[j][i] == '#'){
            q = false;
            break;
        }
        if(q){
            for(int j = 0; j < v.size(); j++) v[j][i] = '0';
        }
    }
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) if(v[i][j] != '0') cout << v[i][j];
        cout << endl;
    }
}
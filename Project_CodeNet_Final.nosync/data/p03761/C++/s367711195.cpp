//C - Dubious Document: 
//Assunto: 
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop(i, a, b) for(int i = a; i < b; i++)
#define loopBack(i, a, b) for(int i = a; i >= b; i--)
#define INF INT_MAX
#define LINF LLONG_MAX
#define DINF DBL_MAX
#define MAX 100050
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    map<char, int> show;
    string ans = "";
    int n;
    cin >> n;
    vector<string> strings(n);
    loop(i, 0, n) cin >> strings[i];
    loop(i, 0, strings[0].size()) show[strings[0][i]]++;
    loop(i, 1, n) {
        map<char, int> aux;
        loop(j, 0, strings[i].size()) aux[strings[i][j]]++;
        for(auto x : show) {
            //cout << x.fi << " " << x.se << "\n";
            show[x.fi] = min(aux[x.fi], x.se);
        }
    }
    for(auto x : show) {
        while(x.se--) ans += x.fi;
    }
    cout << ans << "\n";
}
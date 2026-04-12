#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

vector<int> alphabet(26, 1e9);

int main(){
    int n;
    cin >> n;
    rep(i, n){
        string s;
        cin >> s;
        vector<int> al(26, 0);
        rep(j, s.size()){
            int c = s[j] - 'a';
            al[c]++;
        }
        rep(j, 26){
            alphabet[j] = min(alphabet[j], al[j]);
        }
    }

    rep(i, 26){
        rep(j, alphabet[i]){
            char c = 'a' + i;
            cout << c;
        }
    }
    cout << endl;

    return 0;
}
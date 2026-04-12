#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

int main(){
    int n;
    cin >> n;

    map<char, int> m[55];
    rep(i,n){
        string s;
        cin >> s;
        rep(j,s.size()){
            m[i][s[j]]++;
        }
    }

    rep(i,'z' - 'a' + 1){
        int mini = INF;
        rep(j,n){
            mini = min(m[j][i + 'a'], mini);
        }
        rep(j,mini){
            cout << static_cast<char>('a' + i);
        }
    }
    cout << endl;
}

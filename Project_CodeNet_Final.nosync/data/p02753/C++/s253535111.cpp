
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    bool run=true;
    if(s[0] == s[1] && s[1] == s[2]){
        run = false;
    }
    if(run){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
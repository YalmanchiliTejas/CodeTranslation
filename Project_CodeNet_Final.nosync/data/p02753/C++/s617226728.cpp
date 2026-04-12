#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string S;
    cin >> S;
    bool a = false, b = false;
    for(char c: S){
        if(c == 'A') a = true;
        if(c == 'B') b = true;
    }
    if(a && b) cout << "Yes" << endl;
    else cout << "No" << endl;
}
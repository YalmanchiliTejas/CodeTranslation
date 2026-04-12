#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;
const int INF=10000000;

int main() {
    string s;
    cin >> s;
    bool ok=false;
    for(int i=0;i<2;++i) {
        if(s[i]!=s[i+1]) ok=true;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}


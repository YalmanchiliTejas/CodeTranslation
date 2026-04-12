#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    bool a=0,b=0;
    string s;cin>>s;
    for(auto x:s) if(x=='A') a=1;else b=1;
    if(a&&b) cout<<"Yes";else cout<<"No";
    return 0;
}
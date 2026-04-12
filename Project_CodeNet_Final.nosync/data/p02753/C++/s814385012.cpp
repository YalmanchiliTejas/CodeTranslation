#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF=1001001001;

int main() {
    string s;
    cin>>s;
    int x=0;
    int y=0;
    rep(i,3) {
        if(s[i]=='A') x++;
        if(s[i]=='B') y++;
    }
    if(x!=0&&y!=0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
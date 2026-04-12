#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n"
#define deb(x) cerr << #x << ":" << x << "\n"

void DP_82(){
    string s;
    cin>>s;
    if(s[0]!=s[1] || s[0]!=s[2] || s[1]!=s[2])cout<<"Yes";
    else cout<<"No";
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    DP_82();
    return 0;
}
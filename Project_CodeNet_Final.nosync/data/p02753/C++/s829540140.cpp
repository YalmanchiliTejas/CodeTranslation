#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin>>S;

    if (S[0] == S[1] && S[0] == S[2]) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    string s;cin >> s;
    if(s[0]==s[1]&&s[1]==s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
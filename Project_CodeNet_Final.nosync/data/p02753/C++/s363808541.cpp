#include <bits/stdc++.h>
using namespace std;

#define rep2(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) rep2(i,0,n)
#define all(a) a.begin(),a.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(15);
    
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    

    return 0;
}
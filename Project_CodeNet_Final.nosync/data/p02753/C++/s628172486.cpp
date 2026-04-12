#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define debug freopen("input", "r", stdin);freopen("output", "w", stdout)
#define endl '\n'
#define all(var) var.begin(), var.end()
int const MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
    map < char , bool > mp;
    string s; cin >> s;
    for(auto i: s)
        mp[i] = true;
    if(mp.size() == 2) cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

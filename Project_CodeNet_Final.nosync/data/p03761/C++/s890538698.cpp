#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> count(n, vector<ll>(27, 0));
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(char c : s){
            count.at(i).at(c - 'a')++;
        }
    }

    vector<ll> mincount(27, 100);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 27; ++j){
            mincount.at(j) = min(mincount.at(j), count.at(i).at(j));
        }
    }

    string ans;
    for(int i = 0; i < 27; ++i){
        for(int j = 0; j < mincount.at(i); ++j){
            ans.push_back('a' + (char)i);
        }
    }
    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> count(27, vector<ll>(n, 0));
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(char c : s){
            count.at(c - 'a').at(i)++;
        }
    }

    vector<ll> mincount(27);
    for(int j = 0; j < 27; ++j){
        mincount.at(j) = *min_element(count.at(j).begin(), count.at(j).end());
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

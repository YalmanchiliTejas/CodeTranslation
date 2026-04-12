#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<string> S(N);
    for(int i = 0; i <N; i++) cin >> S[i];

    unordered_map<char, int> mp;
    for(int i = 0; i < S[0].size() ;i++) mp[S[0][i]]++;

    for(int i = 1; i < S.size(); i++){
        unordered_map<char,int> tmp;
        for(auto e: S[i]){
            tmp[e]++;
        }
        for(auto e: mp){
            mp[e.first] = min(mp[e.first], tmp[e.first]);
        }
    }
    string ans;
    for(auto e: mp){
        for(int i = 0; i < e.second; i++){
            ans += e.first;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans << endl;
}
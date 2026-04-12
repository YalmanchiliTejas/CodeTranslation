#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

void solve(long long n, std::vector<std::string> S){
    //vector<map<ll, ll>> vec;
    //map<char, ll> mp;
    vector<vector<ll>> vec;
    for(ll i = 0; i < n; ++i){
        vector<ll> az;
        for(char j = 'a'; j <= 'z'; ++j){
            az.push_back((ll)count(S[i].begin(),S[i].end(), j));
        }
        vec.push_back(az);
        //for(auto i: cnt_vec) cout << i << endl;
    }
    //cout << vec[0].size() << endl;
    vector<ll> ans(vec[0].size(), INF);
    for(ll i = 0; i < vec[0].size(); ++i){
        for(ll j = 0; j < n; ++j){
            ans[i] = min(ans[i], vec[j][i]);
        }
    }
    for(char i = 'a'; i <= 'z'; ++i){
        for(ll j = 0; j < ans[i - 'a']; ++j){
            cout << i;
        }
    }
    cout << endl;
    //for(char i = 'a'; i <= 'z'; ++i) cout << i-'a' << endl;
}

int main(){
    long long n;
    scanf("%lld",&n);
    std::vector<std::string> S(n);
    for(int i = 0 ; i < n ; i++){
        std::cin >> S[i];
    }
    solve(n, std::move(S));
    return 0;
}

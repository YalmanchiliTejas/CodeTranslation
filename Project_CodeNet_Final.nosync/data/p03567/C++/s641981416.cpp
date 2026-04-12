#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define int long long
constexpr long long INF = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;
using Graph = vector<vector<int>>;



signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S;
    cin>>S;

    rep(i,S.size()-1){
        if(S.substr(i,2)=="AC"){
            cout << "Yes"<<endl;
            return 0;
        }
    }
    cout << "No"<<endl;

    



}

#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
const double EPS = 1e-10;
using namespace std;

int main(){
    int H,W;cin >> H >> W;
    vector<vector<int>> vec(W);
    for(int i = 0;i < H;i++){
        string s;cin >> s;
        for(int j = 0;j < W;j++){
            if(s.at(j) == 'B'){
                vec.at(j).push_back(i);
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < W-1;i++){
        for(int j = i;j < W;j++){
            if(vec.at(i).empty() || vec.at(j).empty())continue;
            ans = max(ans, abs(i-j) + abs(vec.at(i).back()-vec.at(j).back()));
            ans = max(ans, abs(i-j) + abs(vec.at(i).back()-vec.at(j).front()));
            ans = max(ans, abs(i-j) + abs(vec.at(i).back()-vec.at(j).back()));
            ans = max(ans, abs(i-j) + abs(vec.at(i).front()-vec.at(j).back()));
        }
    }
    cout<<ans<<endl;
}


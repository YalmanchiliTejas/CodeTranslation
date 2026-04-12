#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr long long INFL = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;
using Graph = vector<vector<int>>;



int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string S[n];
    rep(i,n) cin >> S[i];
    string ans={};
    
    for(char i='a';i<='z';i++){
        int sum=INF;
        rep(k,n){
            int cou=0;
            rep(j,S[k].size()){
                if(i==S[k].at(j)){
                    cou++;
                }
            }
            sum=min(cou,sum);
        }
        rep(j,sum){
            ans+=i;
        }
    }
    cout << ans << endl;



}

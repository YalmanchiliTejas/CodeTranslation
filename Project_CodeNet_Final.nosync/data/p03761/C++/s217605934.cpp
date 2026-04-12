#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
#define LINF (long long)4e18

using ll = long long;


int main(){
    int n; cin >> n;
    vector<string> S(n);
    rep(i,n){
        cin >> S[i];
    }
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    vector<vector<int>> T(26,vector<int>(55));
    rep(i,n){
        rep(j,26){
            int cnt = 0;
            rep(k,S[i].size()){
                if(S[i][k] == alphabet[j]) cnt++;
            }
            T[alphabet[j] - 'a'][cnt]++;
        }
    }

    string ans = "";
    rep(i,26){
        int num = 0;
        for(int j = 54; j >= 0; j--){
            num += T[i][j];
            if(num >= n){
                rep(k,j){
                    ans += i + 'a';
                }
                break;
            }
        }
    }
    cout << ans << endl;
}


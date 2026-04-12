#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }
    string ans;
    for(char c = 'a'; c <= 'z'; c++){

        int len = 50;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < s[i].size(); j++){
                if(s[i][j] == c) count++;
            }
            len = min(len, count);
        }
        
        for(int i = 0; i < len; i++){
            ans += c;
        }
    }
    cout << ans << endl;
}

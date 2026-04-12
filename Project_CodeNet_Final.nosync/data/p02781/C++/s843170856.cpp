#include<bits/stdc++.h>
using namespace std;

int k;
string S;
int ans;

void in();
void solve();
void out();
int backtrack(int i, int K, bool b);
int Ch(int a, int b);

int main(){
    in();
    solve();
    out();
}

void in(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> S >> k;
}

void solve(){
    ans = backtrack(0, k, 1);
}

int backtrack(int i, int K, bool b){
    if(K == 0)
        return 1;
    if(i == S.size())
        return 0;
    if(!b){
        int wow = S.size() - i;
        return Ch(wow, K) * pow(9, K);
    }
    int ans = 0;
    if(S[i] == '0')
        ans += backtrack(i + 1, K, b);
    else
        ans += backtrack(i + 1, K, 0) + backtrack(i + 1, K - 1, b) + (S[i] - '0' - 1) * backtrack(i + 1, K - 1, 0);
    return ans;
}

int Ch(int a, int b){
    if(b > a)
        return 0;
    int ans = 1;
    for(int i = 0; i < b; i++)
        ans *= a - i;
    for(int i = 0; i < b; i++)
        ans /= i + 1;
    return ans;
}

void out(){
    cout << ans;
}


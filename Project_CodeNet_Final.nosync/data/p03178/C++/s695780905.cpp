#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int mod = 1e9+7;
typedef long long ll;
int memo[maxn][100],M;
int solve(int pos,int rem){
    if (!pos&& !rem)return 1;
    if (!pos)return 0;
    int &ans = memo[pos][rem];
    if (ans != -1)return ans;
    ans =0;
    for(int i = 0; i < 10;i++)
        ans = (ans+solve(pos-1,(rem+i) % M)) % mod;
    return ans;
}
int solve(string s){
    int sol =0;
    int rem =0;
    int len = s.size();
    for (int i =0; i < len;i++){
        int d = s[i]-'0';
        for (int j=0; j < d;j++){
            sol = (sol+solve(len-i-1,(rem+j) % M)) % mod;
        }
        rem = (rem+d)% M;
    }
    if (!rem)sol = (sol+1)% mod;
    return sol;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen(".in","r",stdin);
    string s;
    cin >> s >> M;
    memset(memo,-1,sizeof memo);
    cout << (solve(s)-1+mod) % mod;
    return 0;
}

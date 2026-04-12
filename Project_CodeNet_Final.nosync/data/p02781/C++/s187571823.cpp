#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvl = vector<vector<long>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

vector<vvl> dp(110,vvl(2,vl(4,-1)));
int K;

long rec(string &s, int k = 0,bool tight = true,int sum = 0){
    if(sum > K) return 0;

    if(k == s.size()){
        if(sum == K) return 1;
        else return 0;
    }
    int x = s.at(k) - '0';
    int r = tight ? x : 9;

    long &res = dp[k][tight][sum];

    if(~res) return res;

    res = 0;

    for(int i=0; i<=r ; i++){
        res += rec(s,k+1,tight && i==r,sum + (i!=0));
    }
    return res;
}

int main(){
    string s;
    
    cin >> s >> K;

    cout << rec(s) << endl;

}
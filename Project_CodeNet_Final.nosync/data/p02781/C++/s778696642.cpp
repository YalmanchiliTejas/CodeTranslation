#include <bits/stdc++.h>
using namespace std;

vector<int> num;
const int N=2000;
int n,k;
string s;
int dp[N][5][2];
long long d(int pos, int c, int f){
    if(c > k) return 0;

    if(pos == num.size()){
        if(c == k) {
                return 1;
        }
        return 0;
    }

    if(dp[pos][c][f] != -1) return dp[pos][c][f];
    long long res = 0;

    int x;

    if(f == 0){
        x = num[pos];
    } else {
        x = 9;
    }
    for(int i = 0; i<=x; i++){
        int nf = f;
        int ncnt = c;
        if(f == 0 && i < x) nf = 1;
        if(i != 0) ncnt++;
        if(ncnt <= k) res += d(pos+1, ncnt, nf);
    }

    return dp[pos][c][f] = res;
}

long long solve(string s){
    num.clear();
    for(int i=0;i<s.size();i++){
        num.push_back(s[i]-'0');
    }
    memset(dp, -1, sizeof(dp));
    long long res = d(0, 0, 0);
    return res;
}

int main () {
    cin>>s;
    scanf("%d",&k);
    long long res = solve(s);
    printf("%lld",res);
}

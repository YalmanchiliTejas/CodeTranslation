#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

const int n_max = 105;
const int k_max = 4;
ll dp[n_max][k_max][2] = { 0};


int main()
{
    string s;
    int nz;
    cin >> s >> nz;
    int n = s.size();
    vector<int> num(n);
    rep(i, n) num[i] = s[i]-'0';

    // dp[i][j][k]: 上位i+1桁目時点で非ゼロの数がj個である場合の数(k=0のとき、上限値と同じ数であることをしめす)


    // rep(k, 2){
    //     cout << "k=" << k << endl << endl;
    //     rep(i, n){
    //         rep(j, nz+1){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    dp[0][0][1] = 1;
    dp[0][1][1] = num[0]-1;
    dp[0][1][0] = 1;

    rep(i, n-1)rep(j, nz+1)rep(k, 2){
        int ni = i+1;
        rep(d, 10){
            int nj = j;int nk = k;        
            if (d != 0) nj++;
            if (nk == 0){
                if (d > num[i+1]) continue;
                if (d < num[i+1]) nk = 1;
            }
            if (nj > nz) continue;
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }

    // rep(k, 2){
    //     cout << "k=" << k << endl << endl;
    //     rep(i, n){
    //         rep(j, nz+1){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    cout << dp[n-1][nz][0] + dp[n-1][nz][1] << endl;
}


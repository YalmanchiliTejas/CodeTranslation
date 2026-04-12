#include <bits/stdc++.h>
using namespace std;

#define int int64_t

vector< vector<int> >v , patty;
vector<int>dp , cnt;

void init() {
    int i,j;
    v.resize(51);
    patty.resize(51);
    dp.resize(51);
    cnt.resize(51);
    v[0] = {1};
    patty[0] = {1};
    dp[0] = 1;
    cnt[0] = 1;
    for(i=1;i<=50;++i) {
        dp[i] = 2 * dp[i-1] + 3;
        cnt[i] = 2 * cnt[i-1] + 1;
        v[i] = {1 , dp[i-1] , 1 , dp[i-1] , 1};
        patty[i] = {0 , cnt[i-1] , 1 , cnt[i-1] , 0};
    }
}

int solve(int n , int ele) {
    if(n == 1) {
        if(ele == 1) return 0;
        if(ele == 5) return 3;
        else return ele - 1;
    }
    // cout << n << ' ' << ele << endl;
    int s1[6] = {0} , s2[6] = {0};
    for(int i = 0; i < 5;++i) {
        s1[i+1] = s1[i] + v[n][i];
        s2[i+1] = s2[i] + patty[n][i];
    }
    // cout << "THE Contents\n";
    // for(auto x:v[n]) cout << x << ' ';cout << endl;
    // for(auto x:patty[n]) cout << x << ' ';cout << endl;
    // for(auto x:s1) cout << x << ' ';cout << endl;
    // for(auto x:s2) cout << x << ' ';cout << endl;
    int count = 0;
    for(int i=1;i<=5;++i) if(s1[i] == ele) return s2[i];
    for(int i=1;i<=5;++i) {
        if(s1[i] > ele) {
            count = s2[i-1];
            count += solve(n-1 , v[n][i-1] - (s1[i] - ele));
            break;
        }
    }
    return count;
}

int32_t main() {
    auto z = clock();
	init();
	int n , k, i , j , l;
	cin >> n >> k;
	cout << solve(n , k) << endl;
	cerr << (clock() - z)/CLOCKS_PER_SEC;
	return 0;
}
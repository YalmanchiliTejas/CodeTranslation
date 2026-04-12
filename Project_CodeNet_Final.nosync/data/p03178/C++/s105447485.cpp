#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define pr pair

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 5005

void add_slef(int &a, int b, int mod = 0) {
    a += b;
    if(mod > 0 && a >= mod) a -= mod;
}

void sub_slef(int &a, int b, int mod = 0) {
    a -= b;
    if(mod > 0 && a < 0) a += mod;
}

vector<string> split(string s, string del) {
        vector<string> ans;
        if(s.size() == 0) {
            return ans;
        }
        size_t pos = 0;
        while((pos = s.find(del)) != string::npos) {
            string str = s.substr(0, pos);
            ans.push_back(str);
            s.erase(0, pos + del.size());
        }
        return ans;
}
const int mod = 1e9 + 7;

// my version of code of this problem

int solve(string s, int d) {
    int n = s.size();
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(10, vector<int>(10)));
    int ans = 0;
    for(int i = 0; i <= s[0]; i++){
        for(int j = 0; j <= s[0]; j++) {
                dp[0][i][j] += j;
                if(dp[0][i][j] == d) ans++;
            }
    }
    
    
    for(int k = 1; k < n; k++) {
        for(int i = 0; i < 10; i++) {
            if(i < s[k-1]) {
                for(int j = 0; j < 10; j++) {
                    add_slef(dp[k][i][j], (dp[k-1][i][i] + j),mod);
                    if(dp[k][i][j] == d) {
                        ans++;
                    }
                }
            } else if(i == s[k-1]) {
                for(int j = 0; j <= s[k]; j++) {
                    add_slef(dp[k][i][j], (dp[k-1][i][i] + j),mod);
                    if(dp[k][i][j] == d) {
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    string s;
    cin >> s;
    int d;
    cin >> d;
    //cout << solve(s, d) << endl;
    vector<vector<int>> dp(d, vector<int>(2));
    dp[0][0] = 1;
    // dp[sum][sm_already] -> number of ways to choose digit so far such that sum of digit is sum moduel D
    // and smaller aready means we choose already digits which are smaller than k
    for(int i = 0; i < s.size(); i++) {
        vector<vector<int>> new_dp(d, vector<int>(2));
        for(int sum = 0; sum < d; sum++) {
            for(bool sm_already : {false, true}) {
                for(int digit = 0; digit < 10; digit++) {
                    if(digit > s[i] - '0' && !sm_already) {
                        break;
                    }
                    add_slef(new_dp[(sum+digit)%d][sm_already || digit < s[i] - '0'], dp[sum][sm_already], mod);
                }
            }
        }
        dp = new_dp;
    }
    int ans = (dp[0][false] + dp[0][true])%mod;
    ans--;
    if(ans == -1) {
        ans = mod - 1;
    }
    cout << ans << endl;
    return 0;
}

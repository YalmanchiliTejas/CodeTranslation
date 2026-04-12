#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define f(i, a, b) for (int i=a; i<(signed)(b); ++i)
#define pc __builtin_popcount // counts number of 1's in bin(num)

const double pi = 2*acos(0.0);
//__gcd(n1, n2);
//cout << fixed;
//cout << setprecision(6); //fixes # of dp


int dp[110][100][2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	
    string s; int k;
    cin >> s >> k;
    dp[0][0][0] = 1;
    f(i, 0, s.length()) {
        int tmp = s[i] - '0';
        f(j, 0, 5) {
            f(l, 0, 2) {
                for (int d = 0; d <= (l ? 9 : tmp); ++d) {
                    dp[i + 1][j + (d != 0)][l || (d < tmp)] += dp[i][j][l];
                }
            }
        }
    }
    cout << dp[s.size()][k][0] + dp[s.size()][k][1] << endl;
    

}   







#include "bits/stdc++.h"

//region Template
#include "ext/pb_ds/assoc_container.hpp"

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MOD = 1000000007;
using namespace std;
#define finish(x) cout << x; exit(0);
#define fastIO cin.tie(0); cin.sync_with_stdio(false);

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

//const string USCAO_TAG = "mountains";
void usaco(const string& USACO_TAG) { setIn(USACO_TAG + ".in"); setOut(USACO_TAG + ".out"); }
/*
template<typename... Args>
void print(Args... args) {
	#ifdef LOCAL
	((std::cout << args << " "), ...);
	cout << endl;
	#endif
}
 */
//endregion

/* Notes:
 * Farah </3
 */

const int MAXN = 1e5 + 5;
const int INF = 2e9;
ll dp[101][5][2];


ll get(string n, int k){
    dp[0][1][0] = max(0, (n[0] - '0') - 1 );
    dp[0][0][0] = 1;
    int cnt = 0;
    for(int i = 0; i < n.size(); i++){
        cnt += (n[i] - '0') != 0;
        if(cnt <= k)
            dp[i][cnt][1] = 1;
    }
    for(int i = 1; i < n.size(); i++){
        for(int j = 0; j <= k; j++){
            if(j != 0)
                dp[i][j][0] = dp[i - 1][j - 1][0] * 9 + max(0, n[i] - '0' - 1) * dp[i - 1][j - 1][1]
            + dp[i - 1][j][0] + dp[i - 1][j][1] * (n[i] > '0');
            else
                dp[i][j][0]  = dp[i - 1][j][0] + dp[i - 1][j][1] * (n[i] > '0');

        }
    }

    return dp[(int)n.size() - 1][k][0] + dp[(int)n.size() - 1][k][1];
}

int main() {
    //usaco("milkvisits");

#ifdef LOCAL
    //setIn("in.txt");
    //setOut("out.txt");
#endif


    string n;
    int k;

    cin >> n >> k;
    cout << get(n , k) << endl;

   /* ll ans = 0, ans2 = 0;
    *//*for(int i = 0; i < n.size() - 1; i++){
        ans += get(string(i + 1, '9'), k);
    }
    ans += get(n, k);

    multiset<char> s(n.begin(), n.end());*//*

    for(int i = 1; i <= atoi(n.c_str()); i++){
        string str = to_string(i);
        //cout << str << endl;
        multiset<char> s(str.begin(), str.end());

        if(str.size() - s.count('0') == k) ans2++;
    }
    cout << ans2;*/
}
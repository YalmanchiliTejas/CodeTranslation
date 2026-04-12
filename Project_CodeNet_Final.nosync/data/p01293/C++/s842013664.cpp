#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    char trump;
    string str = "0123456789TJQKA";
    while(1){
        cin >> trump;
        if(trump == '#') break;
        string d[4][13];
        rep(i, 0, 4){
            rep(j, 0, 13) cin >> d[i][j];
        }
        int ans = 0; 
        int prev = 0;
        rep(i, 0, 13){
            int MAX = -1, MAXid = -1;
            bool istrump = false;
            char suit = d[prev][i][1];
            rep(j, 0, 4){
                string now = d[j][i];
                int num = str.find(now[0]);
                // cout << now << ' ' << num << endl;
                if(istrump){
                    if(now[1] == trump && num > MAX){
                        MAX = num; MAXid = j;
                    }
                }else{
                    if(now[1] == trump){
                        MAX = num; MAXid = j; istrump = true;
                    }else if(now[1] == suit && num > MAX){
                        MAX = num; MAXid = j;
                    }
                }
            }
            // cout << MAXid << ' ' << MAX << endl;
            prev = MAXid;
            if(MAXid % 2 == 0) ans++;
        }
        if(ans > 6){
            cout << "NS " << ans - 6 << endl; 
        }else{
            cout << "EW " << 7 - ans << endl; 
        }
    }
}

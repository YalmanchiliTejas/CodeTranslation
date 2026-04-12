#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P; 
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// DAME:

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int k;
    cin >> s >> k;
    if (s.size() < k){
        cout << 0 << endl;
        return 0;
    }
    int n = s.size();

    if (k==1){
        ll ans = (n-1)*9 + (s[0]-'0');
        cout << max(ans, 0LL) << endl;
        return 0;
    }else if (k==2){
        ll ans = 0LL;
        ans = (n-1)*(n-2)/2 * 81;
        ans += (s[0]-'0'-1) * (n-1) * 9;
        for(int i=1; i<n; i++){
            if (s[i] != '0'){
                ans += (n-1-i)*9;
                ans += (s[i]-'0');
                break;
            }
        }
        cout << max(ans, 0LL) << endl;
    }else if (k==3){
        ll ans = 0LL;
        ans = (n-1)*(n-2)*(n-3)/6 * 81 * 9;
        ans += (s[0]-'0'-1) * (n-1)*(n-2)/2 * 81;

        int count = 0;
        int prei = 0;
        for(int i=1; i<n; i++){
            if (count == 2) break;
            if (s[i]!='0'){
                if (count==0){
                    if (i == n-1) break;
                    prei = i;
                }else{
                    // 1つ目を選んで実際の値で, 2つ目を選ばない
                    ans += max((n-i-1)*9, 0);
                
                    // 1つ目を選んで実際の値で, 2つ目を選ぶ
                    ans += (s[i]-'0');
                }
                count++;
            }
        }
        // １つ目の０以外のもの以下を二つ選ぶ
        ans += (n-prei-1)*(n-prei-2)/2*81;
        // １つ目を選ぶがその値は実際の値より小さい
        ans += (s[prei] - '0' - 1)*(n-prei-1)*9;


        cout << max(ans, 0LL) << endl;
    }
    return 0;
}
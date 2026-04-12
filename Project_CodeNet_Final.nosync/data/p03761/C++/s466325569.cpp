#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long int ll;
typedef pair<int, int> P;
#define INF 1e9 + 7

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<map<char, int>> v(n);
    rep(i,n){
        string s;
        cin >> s;
        
        rep(j, s.size()){
            v[i][s[j]]++;
        }
    }
    
    string ans = "";
    
    rep(i,26){
        bool flag = true;
        int mm = 51;
        rep(j,n){
            if(v[j].count( (char)('a' + i) ) == 0){
                flag = false;
            }
            else{
                // cout << (char)('a' + i) << endl;
                mm = min(mm, v[j][(char)('a' + i)]);
            }
        }
        
        if(flag){
            // cout << (char)('a' + i) << endl;
            rep(j,mm) ans += (char)('a' + i);
        }
    }
    
    cout << ans << endl;

    return 0;
}
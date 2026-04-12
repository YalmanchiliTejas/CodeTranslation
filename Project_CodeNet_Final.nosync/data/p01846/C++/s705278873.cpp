#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<vector<vector<char> >,int> P;
const long long int MOD = 1000000007;
const int INF = 1000000000;

string s;
int h, w;
char b[9][9];

void solve(){
    int ta = 0, yo = 0;
    rep(i,s.size()){
        if(s[i] == '/'){
            yo = 0;
            ta++;
            continue;
        }
        if('0' <= s[i] && s[i] <= '9'){
            int j = s[i]-'0';
            while(j){
                j--;
                b[ta][yo] = '_';
                yo++;
            }
        } else{
            b[ta][yo] = s[i];
            yo++;
        }
    }
    h = ta+1; w = yo;
    int x, y, xx, yy;
    cin >> y >> x >> yy >> xx;
    y--; x--; yy--; xx--;
    b[y][x] = '_';
    b[yy][xx] = 'b';
    string ans;
    rep(i,h){
        int now = 0;
        rep(j,w){
            if(b[i][j] == '_'){
                now++;
            } else{
                if(now > 0){
                    char num = '0'+now;
                    ans.push_back(num);
                }
                ans.push_back('b');
                now = 0;
            }
        }
        if(now > 0){
            char num = '0'+now;
            ans.push_back(num);
        }
        if(i != h-1) ans.push_back('/');
    }
    cout << ans << endl;
}

int main(){
    while(cin >> s){
        if(s == "#") break;
        solve();
    }
}
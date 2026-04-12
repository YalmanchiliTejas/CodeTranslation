#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (int i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,v) for (int i = 0; i < v.size(); i++)
#define RREPALL(i,v) for (int i = v.size()-1; i >= 0; i--)
#define SORT(v) sort(v.begin(), v.end())
#define MIN_ELEMENT(v) min_element(v.begin(), v.end())
#define MAX_ELEMENT(v) max_element(v.begin(), v.end())
#define COUNT(v,n) count(v.begin(), v.end(), n);
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e7;
const ll MOD = 1e9 + 7;

string s;
int a, b, c, d;
vector<vector<char>> cells;
vector<string> ans;

bool solve()
{
    cin>>a>>b>>c>>d;
    int idx = 0;
    string r;
    cells.push_back({});
    REPALL(i,s) {
        if (s[i] == 'b') {
            cells[idx].push_back('b');
        } else if (s[i] == '/') {
            cells.push_back({});
            idx++;
        } else {
            int cnt = (int)(s[i] - '0');
            REP(j,cnt) cells[idx].push_back('.');
        }
    }
    /*REPALL(i,cells) {
        REPALL(j,cells[i]) {
            cout<<s[i];
        }
        cout<<endl;
    }*/
    cells[a-1][b-1] = '.';
    cells[c-1][d-1] = 'b';

    REPALL(i,cells) {
        int cnt = 0;
        REPALL(j,cells[i]) {
            if (cells[i][j] == 'b') {
                if (cnt != 0) {
                    r += to_string(cnt);
                }
                cnt = 0;
                r += 'b';
            } else {
                cnt++;
            }
        }
        if (cnt != 0) {
            r += to_string(cnt);
        }
        if (i != cells.size() -1)
            r += '/';
    }
    ans.push_back(r);
    cells.clear();
}

int main()
{
    while (cin>>s, s != "#") {
        solve();
    }
    REPALL(i,ans) cout<<ans[i]<<endl;
}

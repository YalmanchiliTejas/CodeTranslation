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

vector<int> num(26, INF);

int main()
{
    int n;
    cin>>n;
    REP(i,n) {
        string s;
        cin>>s;
        vector<int> nnum(26, 0);
        REPALL(j,s) {
            nnum[(int)(s[j] - 'a')]++;
        }
        REP(j,26) {
            num[j] = min(num[j], nnum[j]);
        }
    }
    string ans = "";
    REP(i,26) {
        REP(j,num[i]) {
            ans += (char)(i + 'a');
        }
    }
    cout<<ans<<endl;

    return 0;
}

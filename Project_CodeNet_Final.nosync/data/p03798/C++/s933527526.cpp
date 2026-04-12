#include <bits/stdc++.h>
#define base 1000000007LL
#define ll long long
#define X first
#define Y second
#define pb push_back
#define MAXN 21010
#define Scan(a) scanf("%I64d", &a)
#define CLR(a) memset(a,0,sizeof(a))
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORE(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)

using namespace std;

typedef pair<int, int> II;
typedef vector<II> vi;

int n;
string s;
char res[100010];

bool solve()
{
    char ch = res[n];
    FOR(i,2,n-1)
        if (res[i] == 'W') {
            if (s[i] == 'o') {
                if (res[i-1] == 'W') res[i+1] = 'S';
                else res[i+1] = 'W';
            }
            else res[i+1] = res[i-1];
        }
        else {
            if (s[i] == 'o') res[i+1] = res[i-1];
            else {
                if (res[i-1] == 'W') res[i+1] = 'S';
                else res[i+1] = 'W';
            }
        }
    if (ch != res[n]) return false;
    if (res[n] == 'W') {
        if (s[n] == 'o') {
            if (res[1] != res[n-1]) return true;
        }
        else {
            if (res[1] == res[n-1]) return true;
        }
    }
    else {
        if (s[n] == 'x') {
            if (res[1] != res[n-1]) return true;
        }
        else {
            if (res[1] == res[n-1]) return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> s;
    s = " " + s;
    res[1] = 'S';
    if (s[1] == 'o') {
        res[n] = res[2] = 'W';
        if (solve()) {
            FOR(i,1,n) cout << res[i];
            return 0;
        }
        res[n] = res[2] = 'S';
        if (solve()) {
            FOR(i,1,n) cout << res[i];
            return 0;
        }
    }
    else {
        res[n] = 'W'; res[2] = 'S';
        if (solve()) {
            FOR(i,1,n) cout << res[i];
            return 0;
        }
        res[n] = 'S'; res[2] = 'W';
        if (solve()) {
            FOR(i,1,n) cout << res[i];
            return 0;
        }
    }
    res[1] = 'W';
    if (s[1] == 'x') {
        res[n] = res[2] = 'W';
        if (solve()) {
            FOR(i,1,n) cout << res[i];
            return 0;
        }
        res[n] = res[2] = 'S';
        if (solve()) {
            FOR(i,1,n) cout << res[i];
            return 0;
        }
    }
    else {
        res[n] = 'W'; res[2] = 'S';
        if (solve()) {
            FOR(i,1,n) cout << res[i];
            return 0;
        }
        res[n] = 'S'; res[2] = 'W';
        if (solve()) {
            FOR(i,1,n) cout << res[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repb(i, n) for (int i = (int)n; i >= 0; i--)
#define reps(i, m, n) for (int i = (int)m; i < (int)n; i++)
#define repsb(i, m, n) for (int i = (int)m; i >= (int)n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define INF 999999999999999999
#define ll long long int
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    ll cnt;
    while (cin >> s, s[0] != '#')
    {
        cnt = 0;
        rep(i, s.size()-1)
        {
            if (s[i] == 'q' || s[i] == 'w' || s[i] == 'e' || s[i] == 'r' || s[i] == 't' || s[i] == 'a' || s[i] == 's' || s[i] == 'd' || s[i] == 'f' || s[i] == 'g' || s[i] == 'z' || s[i] == 'x' || s[i] == 'x' || s[i] == 'c' || s[i] == 'v' || s[i] =='b'){
                if (!(s[i+1] == 'q' || s[i+1] == 'w' || s[i+1] == 'e' || s[i+1] == 'r' || s[i+1] == 't' || s[i+1] == 'a' || s[i+1] == 's' || s[i+1] == 'd' || s[i+1] == 'f' || s[i+1] == 'g' || s[i+1] == 'z' || s[i+1] == 'x' || s[i+1] == 'x' || s[i+1] == 'c' || s[i+1] == 'v' || s[i+1] == 'b'))
                    cnt++;
                    }

            else{
                if (s[i + 1] == 'q' || s[i + 1] == 'w' || s[i + 1] == 'e' || s[i + 1] == 'r' || s[i + 1] == 't' || s[i + 1] == 'a' || s[i + 1] == 's' || s[i + 1] == 'd' || s[i + 1] == 'f' || s[i + 1] == 'g' || s[i + 1] == 'z' || s[i + 1] == 'x' || s[i + 1] == 'x' || s[i + 1] == 'c' || s[i + 1] == 'v' || s[i + 1] == 'b')
                    cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}


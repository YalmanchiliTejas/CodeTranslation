#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr,__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main() {
    string s;
    string left = "qwertasdfgzxcvbb";
    while (cin >> s, s != "#") {
        int cnt = 0;
        bool l = left.find(s[0]) != string::npos;
        FOR(i, 1, s.length()) {
            if (left.find(s[i]) != string::npos) {
                if (!l) {
                    l = !l;
                    cnt++;
                }
            } else {
                if (l) {
                    l = !l;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}
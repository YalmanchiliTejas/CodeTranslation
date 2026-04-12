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
    string line;
    int ans;
    cin >> line;
    cin >> ans;
    vi ns;
    vb ops;
    for (int i = 0; i < line.length()-1; i += 2) {
        ns.push_back(line[i] - '0');
        ops.push_back(line[i+1] == '+');
    }
    ns.push_back(line[line.length()-1] - '0');

    int L = ns[0];
    FOR(i, 1, ns.size()) {
        if (ops[i-1]) {
            L += ns[i];
        } else {
            L *= ns[i];
        }
    }

    FOR(i, 1, ns.size()) {
        if (!ops[i-1]) {
            ns[i] = ns[i-1] * ns[i];
            ns[i-1] = 0;
        }
    }
    int M = accumulate(ALL(ns), 0);

    if (ans == M && ans == L) {
        cout << "U" << endl;
    } else if (ans == M) {
        cout << "M" << endl;
    } else if (ans == L) {
        cout << "L" << endl;
    } else {
        cout << "I" << endl;
    }
}
/*
ID: alec3
LANG: C++14
PROG: highcard
*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
const int MAXN = 100;



int main() {
    //ofstream fout("lightson.out");
    //ifstream fin("lightson.in");
    int n;
    cin >> n;

    if (n >= 30){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;


    return 0;
}

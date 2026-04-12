#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;
#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define rep(i,n) FOR(i,0,n)
#define mset(a,x) memset(a,x,sizeof(a))

int main() {
    int n;
    cin >> n;
    int x = 800 * n;
    int y = 200 * (n / 15);
    cout << x - y << endl;


    return 0;
}
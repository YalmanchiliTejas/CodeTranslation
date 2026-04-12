#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>

#define PB push_back
#define MP make_pair
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define INF (1<<29)
#define LLINF (1LL<<60)
#define MOD 1000000007
#define REP(i, n) for(int i=0;i<n;i++)
using ll = long long;
using namespace std;
typedef pair<int, int> P;

ll ans = 0;

void dfs(int n, ll x) {
    if (x == 0)ans+=0;
    else if (n == 0) {
        //cout << n << ' ' << x << ' ';
        //cout << "AAA" << endl;
        ans+=1;
    }
    else if (n == 1) {
        if (x == 1) {
            //cout << n << ' ' << x << ' ';
            //cout << "BBB" << endl;
            ans+=0;
        }
        else if (x == 5) {
            //cout << n << ' ' << x << ' ';
            //cout << "CCC" << endl;
            ans+=3;
        }
        else {
            //cout << n << ' ' << x << ' ';
            //cout << "DDD" << endl;
            ans+=(x-1);
        }
    }
    else if (x == (pow(2, n + 2) - 3)) {
        ans += pow(2, n + 1) - 1;
    }
    else if (x == pow(2, n + 1) - 3 + 2) {
        //cout << n << ' ' << x << ' ';
        //cout << "EEE" << endl;
        ans+=pow(2, n) - 1 + 1;
    }
    else if (x >= pow(2, n + 1) - 3 + 3) {
        //cout << n << ' ' << x << ' ';
        //cout << "FFF ";
        ans += pow(2, n) - 1 + 1;
        //cout << ans << endl;
        dfs(n - 1, x - (pow(2, n + 1) - 3 + 2));
    }
    else {
        //cout << n << ' ' << x << ' ';
        //cout << "GGG" << endl;
        dfs(n - 1, x - 1);
    }
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    dfs(n,x);
    cout << ans << endl;
    return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<numeric>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<map>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define VSORT(v) sort(v.begin(), v.end());
#define VE vector<int>
#define VEP vector<pair<int,int>>
#define llong long long
#define pb(a) push_back(a)
using namespace std;
const vector<VE> DIR{ {-1,0},{1,0},{0,-1},{0,1} };
const int z = 1000000007;
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
int main() {
    int n;
    cin >> n;
    if (n >= 30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
    
}

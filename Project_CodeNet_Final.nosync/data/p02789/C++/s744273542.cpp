#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

#define min_3(a, b, c) min(a, min(b, c))
#define max_3(a, b, c) max(a, max(b, c))
typedef long long ll;
typedef pair<int, int> P;

ll gcd(ll a, ll b){ return b? gcd(b, a%b):a;}
ll lcm(ll a, ll b){ return a/gcd(a,b)*b;}

int main(){
    int n, m;
    cin >> n >> m;
    if(n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

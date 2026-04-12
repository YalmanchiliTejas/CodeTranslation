#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
#define int lint
const int INF =1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repi(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define pb push_back
signed main(){
    int x;
    cin >> x;
    if(x==3 || x==5 || x==7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
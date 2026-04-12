#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x,y,z;cin>>x>>y>>z;
    int res=0; x-=z;
    res += x/(y+z);
    cout<<res<<endl;
}

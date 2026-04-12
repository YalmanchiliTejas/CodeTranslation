#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int r,g,b;cin>>r>>g>>b;
    if((g*10+b)%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

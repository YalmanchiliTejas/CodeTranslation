#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
const int MOD = 1e9 + 7;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n;cin>>n;
    vector<ll> x(n),tmp(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
        tmp[i]=x[i];
    }
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<n;i++){
        if(x[i]>=tmp[n/2]) cout<<tmp[n/2-1]<<endl;
        else cout<<tmp[n/2]<<endl;
    }
}

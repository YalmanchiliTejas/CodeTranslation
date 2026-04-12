#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<math.h>
#include<bitset>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define LONG_INF 9223372036854775807
#define INF 1000000000LL
#define EPS 1e-10
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define dump(a) rep(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define all(v) v.begin(),v.end()
#define pb push_back


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    if(N==M) cout <<"Yes"<<endl;
    else cout << "No" << endl;

    return 0;
}
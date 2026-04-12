#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int i=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1<<30;
const ll LINF = 1LL<<61;
const int MOD = 1e9+7;

int main(){
    int N;
    cin >> N;
    int x,y;
    x = N*800;
    y = (N/15)*200;
    cout << x - y << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF ((int)1e9)
#define INFLL ((ll)1e18)
#define MOD (1000000007LL)

#define REP(i,m,M) for(int i=m; i<M; i++)
#define REPR(i,M,m) for(int i=M; i>m; i—-)
#define REPLL(i,m,M) for(ll i=m; i<M; i++)
#define REPLLR(i,M,m) for(ll i=M; i>m; i—-)
#define ALL(v) v.begin(),v.end()


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    ll a[200000];
    REP(i, 0, n){
        cin >> a[i];
    }
    
    if(n%2==0){
        for(int i=n; i>0; i-=2){
            cout << a[i-1] << " ";
        }
        for(int i=1; i<n; i+=2){
            cout << a[i-1] << " ";
        }
        cout << endl;
    }else{
        for(int i=n; i>0; i-=2){
            cout << a[i-1] << " ";
        }
        for(int i=2; i<n; i+=2){
            cout << a[i-1] << " ";
        }
        cout << endl;
    }

    
    return 0;
}

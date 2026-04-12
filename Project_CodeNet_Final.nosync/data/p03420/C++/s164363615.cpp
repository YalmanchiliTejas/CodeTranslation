#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    if(k==0){
        cout << n*n << endl;
        return 0;
    }
    for(ll i=k+1;i<=n;i++){
        ll tmp = n/i;
        if(n%i==0){
            ans += tmp*(i-k);
        }else{
            ans += (i-k)*tmp;
            ll x = n-tmp*i;
            if(x>=k){
                ans += x-k+1;
            }
        }
        //cout << i <<" " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
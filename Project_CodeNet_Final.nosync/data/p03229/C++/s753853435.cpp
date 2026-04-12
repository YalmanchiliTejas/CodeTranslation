
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBAG = false;

int main(){

    ll N;
    cin >> N;
    vector<ll> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    sort( all(v) );
    
    vector<ll> tmp;
    if(N % 2 == 0){
        tmp.push_back( v[ N / 2 - 1] );
        for(int i = 0; i < (N / 2 - 1); i++){
            tmp.push_back( v[N - 1 - i] );
            tmp.push_back( v[i] );
        }
        tmp.push_back( v[N / 2] );
        //cout << "size = " << N / 2 - 1 << endl;
        //cout << "size = " << tmp.size() << endl;

        ll ans = 0;
        for(int i = 0; i < N - 1; i++){
            ans += abs( tmp[i] - tmp[i+1] );
        }
        cout << ans << endl;
        return 0;
    }

    tmp.clear();
    tmp.push_back( v[ N / 2] );
    for(int i = 0; i < N / 2; i++){
        tmp.push_back( v[i] );
        tmp.push_back( v[N - 1 - i] );
    }

    ll ans1 = 0;
    for(int i = 0; i < N - 1; i++){
        ans1 += abs( tmp[i] - tmp[i+1] );
    }

    tmp.clear();
    tmp.push_back( v[ N / 2] );
    for(int i = 0; i < N / 2; i++){
        tmp.push_back( v[N - 1 - i] );
        tmp.push_back( v[i] );
    }

    ll ans2 = 0;
    for(int i = 0; i < N - 1; i++){
        ans2 += abs( tmp[i] - tmp[i+1] );
    }

    cout << max(ans1, ans2) << endl;





}
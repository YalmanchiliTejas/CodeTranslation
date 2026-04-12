#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    unordered_map<ll,bool> mp;

    for(int i = 0; i < n; i++){
        mp[a[i]] = true;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(n-j < ans){
                break;
            }
            ll dist = a[j] - a[i];
            ll prev = a[i];
            ll tmp = 1;
            while(true){
                if(mp.find(prev+dist) == mp.end()){
                    break;
                }
                prev += dist;
                tmp++;
            }
            if(tmp > ans){
                ans = tmp;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

const ll INF = 1LL<<60;
const ll MOD = 1000000007;

//cout << fixed << setprecision(10);

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    map<ll,ll> mp;
    for(int i=0;i<N;i++){
        if(i==0){
            mp[-A[i]]++;
        }
        else{
            auto itr=mp.upper_bound(-A[i]);
            if(itr==mp.end()){
                mp[-A[i]]++;
            }
            else{
                itr->second=itr->second-1;
                if(itr->second==0){
                    mp.erase(itr);
                }
                mp[-A[i]]++;
            }
        }
    }
    ll ans=0;
    for(auto e : mp){
        //cout << e.first << " " << e.second << endl;
        ans+=e.second;
    }
    cout << ans << endl;

    return 0;
}
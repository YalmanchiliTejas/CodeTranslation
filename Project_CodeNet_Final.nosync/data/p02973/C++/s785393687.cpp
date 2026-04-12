#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int main()
{
    ll N; cin >> N;
    vector<ll>A(N); for(ll i = 0; i < N; i++) cin >> A[i];
    vector<ll>dp;
    for(auto x:A)
    {
        auto itr = lower_bound(dp.begin(),dp.end(),x);
        if(itr == dp.begin()) dp.insert(itr,x);
        else itr--,*itr = x;
    }
    cout << dp.size() << endl;
}
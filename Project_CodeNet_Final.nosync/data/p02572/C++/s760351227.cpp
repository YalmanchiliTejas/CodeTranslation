#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
template <class type> void printVector(vector<type> vec){
    stringstream ss;
    for(ll i=0;i<vec.size();i++)
    {
        ss<<vec[i];
    }
    cout<<ss.str()<<endl;
}

int main(){
    ll N;
    cin>>N;
    ll mod =(int)pow(10,9)+7;

    vector<ll> A(N,0);

    for(ll i=0;i<N;i++)
    {
        cin>>A[i];
    }

    ll sum=0;
    ll res=0;
    for(ll i=N-2;0<=i;i--)
    {
        sum += A[i+1];
        sum %= mod;
        res += (A[i] * sum) % mod;
        res %= mod;
    }
    cout<<res;
    return 0;
}
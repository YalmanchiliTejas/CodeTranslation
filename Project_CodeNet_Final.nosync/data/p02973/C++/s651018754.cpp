#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()
 
int main(){
    ll n;
    cin >> n;
    vector<ll> dic;
    dic.push_back(10000000000);
    rep(i, n){
        ll a;
        cin >> a;
        ll pos = lower_bound(ALL(dic), a)-dic.begin();
        if(pos==0)dic.insert(dic.begin(), a);
        else if(dic[pos]>=a)pos--;
        dic[pos]=a;
    }
    // rep(i, dic.size())cout << dic[i] << ", ";cout << endl;
    cout << dic.size()-1 << endl;
}
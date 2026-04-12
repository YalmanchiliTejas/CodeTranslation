#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<map>
#include<unordered_map>
#include<queue>
#include<deque>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()
 
int main(){
    ll n, m;
    cin >> n >> m;
    if(m < n)cout << "No";
    else cout << "Yes";
}
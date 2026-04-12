#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;





int main(void){
    ll n;
    cin>>n;
    vector<ll>a(n),dp;
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++){
        auto itr = upper_bound(dp.begin(),dp.end(),a[i],greater<ll>());
        if(itr==dp.end())dp.push_back(a[i]);
        else *itr=a[i];
    }
    cout<<dp.size()<<endl;
    return 0;
}
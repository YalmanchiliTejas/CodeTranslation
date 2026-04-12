#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

ll dp[100010];

int main(void){
    ll n;
    cin>>n;
    vector<ll>a(n),ans;
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++){
        auto itr=upper_bound(ans.begin(),ans.end(),a[i],greater<ll>());
        if(itr==ans.end())ans.push_back(a[i]);
        else *itr=a[i];
    }
    cout<<ans.size()<<endl;
    return 0;
}
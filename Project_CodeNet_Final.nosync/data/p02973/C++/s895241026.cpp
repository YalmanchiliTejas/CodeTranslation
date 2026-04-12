#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod
#define N 1000000

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n,a[200010];
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
	a[i]*=-1;
	a[i]+=1e9;
    }
    vector<ll> v;
    v.push_back(0);
    for(int i=0;i<n;i++){
	auto it=upper_bound(v.begin(),v.end(),a[i]);
	if(it==v.end())v.push_back(a[i]);
	else v[it-v.begin()]=a[i];
    }
    cout<<v.size()-1<<endl;
}



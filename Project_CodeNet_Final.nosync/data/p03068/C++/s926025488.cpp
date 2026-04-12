#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define INF 1e9+7
#define LLINF 1e18
using namespace std;
const ll MOD = 1e9 +7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    string s;
    cin>>n>>s>>k;
    rep(i,n){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }
    cout<<s<<endl;
    return 0;
}
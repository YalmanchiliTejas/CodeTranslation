#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sidha(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int> 
#define pb push_back
#define st string
#define pairi pair<int,int>
#define INF 1000000007
 
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);const ll mod =1000000007;
    ll n;cin >> n;
    vector<ll>a(n);
    sidha(i,0,n) cin >>a.at(i);
    ll ans =0;
    ll b = 0;
    sidha(i,0,n){
        ans = (ans+a.at(i) * b)%mod;
        b = (b+a.at(i))%mod;
    }
    cout << ans << endl;
	return 0;
}
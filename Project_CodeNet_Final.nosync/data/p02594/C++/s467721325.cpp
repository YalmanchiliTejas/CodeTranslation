#include<bits/stdc++.h>
using namespace std;
         
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define mod 1000000007  
const int N = 100001; 



void solve(){
	int n;cin>>n;
	if(n>=30)cout<<"Yes";
	else cout<<"No";
    return;
}
         
signed main(){
        IOS;    
        

        int t=1;
        // cin>>t;
        // fac[0] = 1; 
        // for (int i=1 ; i<=2000001; i++) fac[i] = fac[i-1]*i%mod; 
        rep(i,0,t){
            solve();
            cout<<"\n";
        //   cout<<" * "<<t<<"\n";
        }
    //    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
 
// typedef vector <int> vi;
// typedef pair< int ,int > pii;
// #define all(v) v.begin(),v.end()
// #define PB push_back
// #define T(val) while(val--)
// #define FIN for(i=0;i<n;i++)
// #define FIS for(i=0;i<s.length();i++)
// #define AIN for(i=0;i<n;i++){cin>>a[i];}
// #define F(i,k,n) for(i=k;i<n;i++)
// #define FG(i,k,n,x) for(i=k;i<n;i+=x)
// #define YES cout<<"YES\n"; 
// #define NO cout<<"NO\n"; 
// #define ll long long
// #define MOD 1000000007
// #define deb(x) cout << #x << "=" << x << endl;
// #define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl;
// #define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// //sort(arr, arr+n, greater<int>()); For sorting in reverse order 
// double power(double A,ll n){
//         double p=1;
//         ll k=1;
//         while(k<=n){
//                 if(n&k)
//                         p=p*A;
//                 k=k*2;A=A*A;
//         }
//         return p;
// } 
// int solve(){
//         ll n;
//         cin>>n;
//         double p;
//         cin>>p;
//         cout << fixed << setprecision(12) ;
//         cout<<power((1-p),n)<<"\n";
//   return 0;
// }
// int main(){
// fast
//         int t=1;
//         //cin>>t; 
//         T(t){
//           solve();
//         }
//         return 0;
// }
#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define all(v) v.begin(),v.end()
#define PB push_back
#define T(val) while(val--)
#define FIN for(i=0;i<n;i++)
#define FIS for(i=0;i<s.length();i++)
#define AIN for(i=0;i<n;i++){cin>>a[i];}
#define F(i,k,n) for(i=k;i<n;i++)
#define FG(i,k,n,x) for(i=k;i<n;i+=x)
#define YES cout<<"YES\n"; 
#define NO cout<<"NO\n"; 
#define ll long long
#define MOD 1000000007
#define deb(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//sort(arr, arr+n, greater<int>()); For sorting in reverse order 
 
int solve(){
        ll n;
        cin>>n;
        ll a[n],i,tot=0;
        FIN{
                cin>>a[i];
                tot+=a[i];

        }
        ll dp[n+1][n+1][2];
        // dp[i][i][0]=a[i];||dp[i][i][1]=0;
        for(i=0;i<n;i++){
                for(ll j=0;j+i<n;j++){
                        if(i==0){
                                dp[j][j][0]=a[j];
                                dp[j][j][1]=0;
                                continue;
                        }
                        dp[j][j+i][0]=max(a[j]+dp[j+1][j+i][1],a[j+i]+dp[j][j+i-1][1]);
                        dp[j][j+i][1]=min(dp[j+1][j+i][0],dp[j][j+i-1][0]);
                }
        }
        ll x=dp[0][n-1][0];
        cout<<2*x-tot<<"\n";

  return 0;
}
int main(){
fast
        int t=1;
        // cin>>t; 
        T(t){
          solve();
        }
        return 0;
}
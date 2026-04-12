#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define tarce(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define sa(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define pb push_back
#define inf 2e18
#define scan() int n; cin>>n ; int a[n+1]; for(int i = 1 ; i<=n ; i++) cin>>a[i]
#define scan2() int n,k; cin>>n>>k ; int a[n+1]; for(int i = 1 ; i<=n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
#define mem(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
#define N 200005


int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string s;
        cin >> s;
        int i,ans=0;
        for(i=0; i<s.size()-1; i++){
            if(s[i]!=s[i+1]){
                cout << "Yes";
                return 0;
            }
        }
        cout << "No";
    

}
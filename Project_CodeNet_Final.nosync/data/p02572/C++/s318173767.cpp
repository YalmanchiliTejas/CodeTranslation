#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define ford(b,a) for(int i=b;i>=a;i--)
typedef pair<int, int> pi;
#define PI 3.14159265359
#define vi vector<int>
long long mod=1000000007;
//int count=INT_MAX;
 
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases=1;
    //cin>>testcases;
    //cout<<t;
    //scanf("%d",&t);
    //int t=testcases;
    while(testcases--){
        int n;
        cin>>n;
        ll a[n],p[n];
        fori(0,n){
            cin>>a[i];
        }
        p[n-1]=0LL;
        ford(n-2,0){
            p[i]=(p[i+1]+a[i+1])%mod;
        }
        ll ans=0;
        fori(0,n){
            ans+=(p[i]*a[i])%mod;
        }
        cout<<ans%mod;
    }               

    return 0;
}
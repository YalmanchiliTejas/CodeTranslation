#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define end "\n"
#define inp(arr,n) for(int i=0;i<n;i++) cin>>arr[i]
#define soa(arr,n) sort(arr,arr+n)
#define sov(arr) sort(arr.begin(),arr.end())
#define fr(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    while(t--){
        int x;
        cin>>x;
        if(x>=30) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
#include<bits/stdc++.h>
#define MAX 1000000007
#define ll long long int
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ull unsigned long long int
#define pb push_back
#define eb emplace_back
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin>>t;
    // while(t--){
    // }
    int n;
    cin>>n;

    int arr[n];
    fo(i,0,n){
        cin>>arr[i];
    }
    ll pref[n];
    pref[n-1]=0;

    for(int i=n-2;i>=0;i--){
        pref[i] = (pref[i+1]%MAX + arr[i+1]%MAX)%MAX;
    }

    ll ans=0;

    for(int i=0;i<n-1;i++){
        ans = ((ans)%MAX + ((pref[i])%MAX * (arr[i])%MAX)%MAX)%MAX;
    }

    cout<<ans<<endl;

    return 0;
}
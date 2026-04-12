//submitted by HimJ
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define fr(i,s,e) for(i=s;i<e;i++)
#define ms(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int mxn=1e5+1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  ll t=1;
  //cin>>t;
    while(t--){
        int n,i;
    cin>>n;
    pair<int,int> arr[n];
    fr(i,0,n)
    {
        cin>>arr[i].fi;
        arr[i].se=i;
    }
    int ans[n];
    sort(arr,arr+n);
    fr(i,0,n)
    {
        int left=i;
        int req=(n-1)/2+1;
        if(left<req)
        req-=left;
        else
        {
            ans[arr[i].se]=arr[req-1].fi;
            continue;
        }
        ans[arr[i].se]=arr[req+i].fi;
            
    }
    fr(i,0,n)
    cout<<ans[i]<<"\n";
    

    }
  return 0;
  }


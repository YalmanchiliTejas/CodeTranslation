#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define fr(i,s,e) for(i=s;i<e;i++)
#define ms(arr,val) memset(arr,val,sizeof(arr))
using namespace std;

const int mxn=2e5+1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

  int t=1;
  //cin>>t;
  int tt=1;
  while(t--){
        int n,i;
        cin>>n;
        int arr[n],ans=0;
        fr(i,0,n)
        cin>>arr[i];
        int mx=arr[0];
        ans=1;
        fr(i,1,n)
        {
          if(arr[i]>=mx)
            ans++;
          mx=max(mx,arr[i]);
        }
        cout<<ans;
       //cout<<"Case #"<<tt<<": ";
       //tt++;
    }
  return 0;
}


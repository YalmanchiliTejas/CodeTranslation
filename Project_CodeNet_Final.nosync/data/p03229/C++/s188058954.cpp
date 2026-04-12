#include <bits/stdc++.h>
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int i=0,j=n-1,l=n-2,k=1;
    ll ans=a[j]-a[i];
    while(k<=l){
        if(a[j]-a[k]>a[l]-a[i]){
            ans+=a[j]-a[k];
            j--;
            k++;
        }else{
            ans+=a[l]-a[i];
            i++;
            l--;
        }
    }
    cout<<ans<<endl;
   return 0;   
}
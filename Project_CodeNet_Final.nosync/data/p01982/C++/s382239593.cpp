#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pl pair<ll,ll>
#define rep(i,b) for(ll i=0;i<b;i++)
#define all(v) (v).begin(),(v).end()

int main(){
    int n,l,r;
    while(cin>>n>>l>>r,n){
        int sum=0;
        int a[55];
        rep(i,n)cin>>a[i];
        for(int i=l;i<=r;i++){
            a[n]=i;
            for(int j=0;j<=n;j++){
                if(i%a[j]==0){
                    if(j%2==0)sum++;
                    break;
                }
            }
        }
        cout<<sum<<endl;
    }
}

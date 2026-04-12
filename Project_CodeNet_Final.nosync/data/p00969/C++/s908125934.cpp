#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repc(i,s,n) for(int i=s;i<n;i++)
using namespace std;
int main(void){
    int n,ans=0,x,d,tmp,count;
    cin>>n;
    vector<int> v(n);
    rep(i,n) cin>>v[i];
    sort(v.begin(),v.end());
    rep(i,n){
        x=v[i];
        repc(j,i+1,n){
            d=v[j]-x;
            tmp=v[j];
            count=2;
            while(true){
                if(binary_search(v.begin(), v.end(), tmp+d)){
                    count++;
                    tmp+=d;
                }else{
                    ans=max(ans,count);
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}


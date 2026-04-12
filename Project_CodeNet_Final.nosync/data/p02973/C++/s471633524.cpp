#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int ar[N],hold[N],n;
int upper(int len,int val){
    int l=0;
    int r=len;
    int ans=0;
    while(l<=r){
        int m=(l+r)/2;
        if(hold[m]>=val){
            ans=m;
            l=m+1;
        }else r=m-1;
    }
    return ans;
}
int main()
{ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ar[i];
    int len=1;
    hold[0]=ar[1];
    for(int i=2;i<=n;i++){
        if(ar[i]>hold[0])hold[0]=ar[i];
        else if(ar[i]<=hold[len-1])hold[len++]=ar[i];
        else{
            int pos=upper(len,ar[i]);
            pos++;
            //cout<<hold[pos]<<' '<<ar[i]<<'\n';
            hold[pos]=ar[i];
        }
    }
    /*for(int i=0;i<len;i++)cout<<hold[i]<< ' ';
    cout<<'\n';*/
    cout<<len<<'\n';
    return 0;
}

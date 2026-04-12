#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,sum=0,cnt=0,cnt2=0,a[2000],i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        cnt=0;
        for(j=0;j<i;j++){
            if(a[i]>=a[j])
                cnt++;
        }
        if(cnt==i)
            cnt2++;
    }
    cout<<cnt2;
    
}

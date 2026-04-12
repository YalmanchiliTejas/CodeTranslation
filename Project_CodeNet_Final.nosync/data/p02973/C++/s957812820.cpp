#include<bits/stdc++.h>
using namespace std;
int n,a[100005],s[200005],t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    s[1]=1,t=1;
    for(int i=2;i<=n;i++)
	{
        if(a[i]<=a[s[t]]) s[++t]=i;
        else
		{
            int l=1,r=t;
            while(l<r)
			{
                int mid=(l+r)/2;
                if(a[s[mid]]<a[i]) r=mid;
                else l=mid+1;
            }
            s[l]=i;
        }
    }
    cout<<t;
    return 0;
}
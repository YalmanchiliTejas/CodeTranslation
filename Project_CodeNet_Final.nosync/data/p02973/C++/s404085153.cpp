#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100001];
ll b[100001];

int fun(ll l,ll r,ll v){
    while(l<r){
	ll m=(l+r)/2;
	if((b[m]<=v)&&(b[m+1]>v))
	 return(m);
	else if(b[m+1]<=v)
	l=m+1;
	else
	r=m-1;
    }
    return(l);
}

int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
	a[i]=a[i]*(-1);
    }

//return 0;
    ll len=1;
    b[len]=a[0];
    for(ll i=1;i<n;i++){
        if(a[i]>=b[len])
            b[++len]=a[i];
        else if(a[i]<b[1]){
            b[1]=a[i];
        }
        else{
            b[fun(1,len-1,a[i])+1]=a[i];
        }
    }
    cout<<len;
}
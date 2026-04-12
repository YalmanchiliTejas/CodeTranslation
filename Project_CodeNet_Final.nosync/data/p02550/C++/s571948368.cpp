//Author - Rahil Malhotra
#include "bits/stdc++.h"
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n,x,m;
int arr[100005];
int32_t main()
{
    IOS;
    cin>>n>>x>>m;
    int sum=x;
    int last=x;
    map<int,int>mp;
    arr[1]=x;
    mp[1]=x;
    int ind1=0,ind2=0;
    for(int i=2;i<=n;i++)
    {
        last=(last*last)%m;
        if(mp.find(last)==mp.end())
            mp[last]=i;
        else
        {
            ind1=mp[last];
            ind2=i;
            break;
        }
        sum+=last;
        arr[i]=last;
        arr[i]+=arr[i-1];
    }
    if(ind1==0)
        print(sum);
    else
    {
        int cylength=ind2-ind1;
        int lefttotake=n-ind2+1;
        int full=lefttotake/cylength;
        int moded=lefttotake%cylength;
        sum+=(arr[ind2-1]-arr[ind1-1])*full;
        sum+=(arr[ind1+moded-1]-arr[ind1-1]);
        print(sum);
    }
}   

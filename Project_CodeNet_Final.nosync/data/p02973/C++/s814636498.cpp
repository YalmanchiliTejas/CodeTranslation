#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target ("avx2,avx,fma")
#define ll long long int
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for(i=l;i<r;i++)
#define bep(i,l,r) for(i=l;i>=r;i--)
#define ld long double
#define ff first
#define ss second
#define pii pair<int,int>
int main()
{
    int i,n;
    cin>>n;
    vector<int>a(n);
    cin>>a[0];
    rep(i,1,n)
        cin>>a[i];
    vector<int>arr;
    arr.pb(a[0]);
    rep(i,1,n)
    {
        int l=0;
        int r=arr.size()-1;
        bool f=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]<a[i])
            {
                r=mid-1;
                f=1;
            }
            else
            l=mid+1;
        }
        if(f)
            arr[l]=a[i];
        else
          arr.pb(a[i]);
    }
    cout<<arr.size();
}

//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   
    #ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i;
    cin>>n;

    vector<int>arr(n);

    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    vector<int>v;
    v.push_back(arr[arr.size()-1]);
    
    for(i=arr.size()-2; i>=0; i--)
    {
      int a=arr[i];
      if(a>=v[v.size()-1])
        v.push_back(a);
    else
    {
        int x=upper_bound(v.begin(), v.end(),a)-v.begin();
        //cout<<x<<'\n';
        v[x]=a;
    }
    }
     cout<<v.size()<<'\n';
    // for(auto x: v)
    //     cout<<x<<" ";
    return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;



signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif      

    int n;
    cin>>n;
    if(n>=30)
        cout<<"Yes";
    else
    cout<<"No";

}

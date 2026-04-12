// ~/Remember,remember the 6th of March
 
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-9;
const ll MOD = 1e9 + 7;
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]*=-1;
    }
    vector<int>lcs;
    for(int i=0;i<n;i++)
    {
        int ind=upper_bound(lcs.begin(),lcs.end(),arr[i])-lcs.begin();
        if(ind == lcs.size())
            lcs.push_back(arr[i]);
        else
            lcs[ind]=arr[i];
    }
    cout<<lcs.size()<<endl;
    return 0;
}
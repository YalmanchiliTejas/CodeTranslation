#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int  n;
    cin>>n;
    int arr[n+10];
    multiset<int> s;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for (int i = 1; i <=n; ++i)
    {
        multiset<int> ::iterator it;
        it=s.lower_bound(arr[i]);
        if(it==s.begin())
        {
            s.insert(arr[i]);
        }else{
            it--;
            s.erase(it);
            s.insert(arr[i]);
        }
        
    }

   cout<<s.size();
    return 0;
}
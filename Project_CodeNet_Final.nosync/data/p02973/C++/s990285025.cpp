#include<iostream>
#include<set>
using namespace std;
int n;
main()
{
    cin>>n;
    multiset<int> s;
    for(int i=0;i<n;i++)s.insert(-1);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        multiset<int>::iterator it=s.lower_bound(a);
        it--;
        if(*it==-1)ans++;
        s.erase(it);
        s.insert(a);
    }
    cout<<ans<<endl;
}
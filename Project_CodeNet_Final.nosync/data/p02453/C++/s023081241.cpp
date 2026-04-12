#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a;
    cin>>a;
    vector<int > v;
    for(int i=0;i<a;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        int pos=lower_bound(v.begin(),v.end(),t)-v.begin();
        cout<<pos<<endl;
    }
    
}

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    deque<int> d;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(!i)
            d.push_back(a);
        else
        {
            if(i%2)
                d.push_back(a);
            else
                d.push_front(a);
        }
    }
    if(n%2==0)
        reverse(d.begin(),d.end());
    for(int i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        cout<<d[i];
    }
    cout<<endl;
    return 0;
}
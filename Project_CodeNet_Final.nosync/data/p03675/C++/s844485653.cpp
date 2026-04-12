#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;
int rev,n,i,j,x;
deque<int> d;

int main()
{
    cin>>n;
    rev=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(rev%2==0) d.push_front(x);
        else d.push_back(x);
        rev++;
    }
    for(i=1;i<=n;i++)
    {
        if(rev%2==1)
        {
            cout<<d.front()<<' ';
            d.pop_front();
        }
        else
        {
            cout<<d.back()<<' ';
            d.pop_back();
        }
    }
    cout<<'\n';
    return 0;
}

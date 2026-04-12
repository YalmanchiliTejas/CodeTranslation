#include<iostream>
#include<deque>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    int a;
    deque<int>b;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        int it= lower_bound(b.begin(),b.end(),a)-b.begin();
        if(!it)
            b.push_front(a);
        else
            b[it-1]=a;
    }
    cout<<b.size()<<endl;

    return 0;
}
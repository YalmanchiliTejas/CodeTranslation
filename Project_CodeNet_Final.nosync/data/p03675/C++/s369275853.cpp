#include<iostream>
#include<deque>
using namespace std;
const int N=200100;
int n,a[N];
deque<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    bool f=0;
    for(int i=1;i<=n;++i)
    {
        int t;
        cin>>t;
        if(!f)
            q.push_back(t);
        else 
            q.push_front(t);
        f=!f;
    }
    if(!f)
        while(!q.empty())
        {
            cout<<q.front()<<' ';
            q.pop_front();
        }
    else
        while(!q.empty())
        {
            cout<<q.back()<<' ';
            q.pop_back();
        }
    cout<<endl;
    return 0;
}
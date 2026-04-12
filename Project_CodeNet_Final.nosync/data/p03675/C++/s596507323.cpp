#include<bits/stdc++.h>

using namespace std;
deque<int> q;
int v[200005],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    if(n%2)
    {
        q.push_back(v[1]);
        for(int i=2;i<=n;i+=2)
        {
            q.push_back(v[i]);
            q.push_front(v[i+1]);
        }

    }
        else
    {
        for(int i=1;i<=n;i+=2)
        {
            q.push_back(v[i]);
            q.push_front(v[i+1]);
        }
    }
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop_front();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    int n,i;
    int x;
    cin>>n;
    deque<int>q;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        if(i%2==0)
            q.push_back(x);
        else
            q.push_front(x);
    }
    if(n%2==0)
        reverse(q.begin(),q.end());
    for(auto it=q.begin(); it!=q.end(); it++)
        cout<<*it<<' ';
    puts("");
    return 0;
}

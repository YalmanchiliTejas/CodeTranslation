#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main()
{
    ll n,temp;
    cin>>n;
    deque<ll> dq;
    deque<ll>::iterator it;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(i%2==0)
        {
            dq.push_back(temp);
        }
        else
        {
            dq.push_front(temp);
        }
    }
    if(n%2!=0)
    {
        reverse(dq.begin(),dq.end());
    }
    for(it=dq.begin();it!=dq.end();it++)
    {
        cout<<*it<<" ";
    }
    printf("\n");


    return 0;
}

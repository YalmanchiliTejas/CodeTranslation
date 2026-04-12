#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,e,f,g,h,i,j;
    string s,s1;
    vector<pair<int,int> >v;
    vector<int>v1;
    map<int,int>m;
    map<int,int>::iterator it;

    cin>>a;

    deque<int>dq;

    for(i=1; i<=a; i++)
    {
        cin>>c;
        if(i%2!=0)
        {

            dq.push_front(c);
        }
        else
        {
            dq.push_back(c);
        }
    }

    if(a%2!=0)
    {
        for( i=0; i<a; i++)
        {
            cout<<dq[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        for( i=a-1; i>=0; i--)
        {
            cout<<dq[i]<<" ";
        }
        cout<<endl;
    }
    return 0;


}

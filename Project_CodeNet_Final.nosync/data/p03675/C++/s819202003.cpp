#include <bits/stdc++.h>

#define MaxN 250005
#define INF 2140000000
#define eps 1e-9

using namespace std;

deque <int> v;

int main()
{
    int N,X;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>X;
        if(i%2!=N%2)
            v.push_back(X);
        else v.push_front(X);
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    return 0;
}

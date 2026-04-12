#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef pair<int,int>   pii;
typedef vector<int>     vi;
typedef long double     ld;
#define MOD         1000000007
#define pb          push_back
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        '\n'
#define PI          3.14159265359d
#define sz(x)       (int)x.size()
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    bool flag;
    cin>>n;
    if(n%2)
        flag=false;
    else
        flag=true;
    deque<int> q;
    while(n--)
    {
        cin>>x;
        if(flag)
            q.push_back(x);
        else
            q.push_front(x);
        flag=!flag;
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop_front();
    }
    return 0;
}

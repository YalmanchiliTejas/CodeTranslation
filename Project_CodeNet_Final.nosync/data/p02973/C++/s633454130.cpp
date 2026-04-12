#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+10;
typedef long long ll;
int a[N];
vector<int>q;
int main ()
{
    int n,c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    cin>>c;
    a[i]=c*-1;
    }
    for(int i=1;i<=n;i++)
    {
        int pos=upper_bound(q.begin(),q.end(),a[i])-q.begin();
        if(pos==q.size())q.push_back(a[i]);
        else    q[pos]=a[i];
    }
    cout<<q.size()<<endl;
    return 0;
}
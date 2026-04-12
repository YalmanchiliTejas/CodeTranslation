#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> v;
    vector<int> vk(n,-1);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int poc=0,k=n-1;
    for(int i=n-1;i>=0;i-=2)
    {
        vk[poc]=v[i];
        if(i)
        vk[k]=v[i-1];
    poc++;
    k--;
    }
    for(int i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        cout<<vk[i];
    }
    return 0;
}
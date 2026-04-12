#include <iostream>
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn =1e5+10;
int a[maxn];
multiset<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        multiset<int>:: iterator it =q.lower_bound(a[i]);
        if(it==q.begin())
            q.insert(a[i]);
        else
        {
            it--;
            q.erase(it);
            q.insert(a[i]);
        }
    }
    cout << q.size();
    return 0;
}

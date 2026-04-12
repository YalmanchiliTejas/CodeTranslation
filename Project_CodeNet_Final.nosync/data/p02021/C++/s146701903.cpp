#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

int main()
{
    int n, a[110], cnt=0;
    bool ok;
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=100; i>=1; i--)
    {
        cnt=0;
        ok=true;
        for (int j=1; j<=n; j++)
        {
            cnt+=a[j];
            cnt-=i;
            if (cnt<0) ok=false;
            if (!ok) break;
        }
        if (ok)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}


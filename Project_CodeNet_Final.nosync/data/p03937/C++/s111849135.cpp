#include<bits/stdc++.h>
using namespace std;
 
int n, m, ans;
 
int main()
{
    cin >> n >> m;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j)
        {
            char x;
            cin >> x;
            if(x=='#')
                ++ans;
        }
    if(ans != n+m-1)
        cout << "Impossible";
    else
        cout << "Possible";
 
    return 0;
}
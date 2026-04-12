/*__ _(_) __ _  ___  ___ _   _  __| | __ _ _   _| |_ ___
 / _` | |/ _` |/ _ \/ __| | | |/ _` |/ _` | | | | __/ _ \
| (_| | | (_| | (_) \__ \ |_| | (_| | (_| | |_| | || (_) |
 \__, |_|\__,_|\___/|___/\__,_|\__,_|\__,_|\__,_|\__\___/
 |___/                                  Accepted Code  */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef gsdt
    freopen("input.txt","r",stdin);
#endif // gsdt

    int m,n,dem=0;
    char a[10][10];
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin>>a[i][j], dem+=a[i][j]=='#';

    int x=1;
    for(int i=1; i<=n; i++){
        while(a[i][x]=='#') x++, dem--;
        x--;
    }

    if(dem) cout<<"Impossible";
    else cout<<"Possible";
    return 0;
}


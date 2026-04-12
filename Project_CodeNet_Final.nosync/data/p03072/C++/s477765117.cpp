#include<bits/stdc++.h>
using namespace std;

//------------Constants----------------
#define N 21
//------------Variables----------------
int n,hmax,ans;
int a[N];
//------------Functions----------------

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//------------Input--------------------
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
//------------Work---------------------
    hmax=a[0];
    ans=1;
    for (int i=1; i<n; i++){
        if (a[i]>=hmax) {hmax=a[i]; ans++;}
    }
    cout << ans;
}

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int r,g,b;cin>>r>>g>>b;
    if ((g*10+b)%4==0)cout<<"YES";
    else cout<<"NO";
    return 0;
}

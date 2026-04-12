#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define db double
#define pb push_back
#define wrln cout<<'\n';
#define pii pair<int,int>

using namespace std;
const int H=1e9+7;
const int N=2e5+100;

unsigned long long res,f[N],a[N],n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.flush();

   // freopen("test11.INP","r",stdin);
   // freopen("test.OUT","w",stdout);

    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        f[i]=a[i]+f[i-1];
    }
    for (int i=n; i>0; i--)
    {
        res+= ( (a[i]%H) *  (f[i-1]%H ) ) %H;
        res%=H;
    }

    cout<<res;
}

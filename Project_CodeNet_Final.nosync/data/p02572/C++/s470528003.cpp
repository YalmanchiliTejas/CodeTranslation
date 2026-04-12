/* To Kaise Hain Aaplog*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) (x).begin(), (x).end()

void shuru_krte_hai_bina_kisi_bakchodi_ke()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

const int m = 1e9+7;

int32_t main()
{
    //shuru_krte_hai_bina_kisi_bakchodi_ke();
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int suff[n-1];
    suff[n-2] = a[n-1];
    for(int i=n-3;i>=0;i--){
        suff[i] = (a[i+1]+suff[i+1])%m;
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        ans = (ans+(suff[i]*a[i])%m)%m;
    }
    cout<<ans<<" ";

    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define next fuck
#define se second
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(auto &x : a) cin>>x;
    sort(a.begin(),a.end());
    ll ans = 0;
    if(n % 2 == 1)
    {
        int mid = (n + 1)/2 -1;
        b[0] = a[mid];
        if(a[mid] - a[mid-1] < a[mid+1] - a[mid])
        {
            for(int i  =0;i<mid;i++)
            {
                b[(i+1)*2] = a[i];
                b[i*2+1] = a[n-i-1];
            }

        }
        else
        {
            for(int i = 0;i<mid;i++)
            {
                b[i*2+1] = a[i];
                b[(i+1)*2] = a[n-i-1];
            }
        }
    }
    else
    {
        int mid = n/2;
        for(int i = 0;i<mid;i++)
        {
            b[i*2+1] = a[i];
            b[i*2] = a[mid+i];
        }
    }
    for(int i = 1;i<n;i++)
    {
        ans += 1LL*abs(b[i] - b[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}

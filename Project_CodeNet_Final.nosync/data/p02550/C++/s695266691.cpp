#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


vector <ll> terms;
map <ll,ll> indexes;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll i,j,k,l,m,n,x;

    cin >> n >> x >> m;

    k = x;
    ll ans= 0;
    j = -1;
    for(i=1;i<=n;i++)
    {
        l = (k%m*k%m)%m;
        terms.push_back(k);
        
        
        if(indexes.find(k) != indexes.end())
        {
            j = indexes[k];
            // cout << indexes[k] << '\n';
            break;
        }
        else
        {
            indexes[k] = i-1;
        }

        ans += k;
        // cout << k << '\n';

        k = l;
    }

    if(j == -1)
    {
        cout << ans << '\n';
        return 0;
    }

    // cout << j << " " << i-2 << '\n';

    // for(k=0;k<j-1;k++)
    // {
    //     ans += terms[k];
    // }

    l = 0;

    for(k=j;k<i-1;k++)
    {
        l += terms[k];

    }

    // cout << "L: " << l << '\n';

    m = (i-j-1);
    ans += l*((n-i+1)/(i-j-1));

    // cout << m << " " << ((n-i+1)/(i-j-1)) << '\n';

    for(k=j;k<j+(n-i+1)%(i-j-1);k++)
    {
        ans += terms[k];
    }

    cout << ans << '\n';

    


}
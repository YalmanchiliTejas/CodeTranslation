#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod=1e9+7;

int main()
{
    /* Faster input ouput */
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    /* To read input from a file and output to a file */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    ll t = 1;
    // cin >> t;
    while(t--)
    {        
        ll n,i,j;
        cin >> n;
        // ll arr[n];

        // for(i=0;i<n;i++)
        // {
        //     cin >> arr[i];
        // }

        if(n >= 30)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        
    }
    
    return 0;
}
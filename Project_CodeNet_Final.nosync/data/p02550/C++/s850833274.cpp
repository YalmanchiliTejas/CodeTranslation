using namespace std;
#include<bits/stdc++.h>
#define int long long
#define pb push_back 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int mod;

signed main()
{
    IOS;
    int n,x,mod;
    cin>>n>>x>>mod;
    int freq[mod]={0};

    vector<int>sequence,cycle;
    
    int ans = 0;
    int rep;

    bool found = false;
    int init = 0;

    while(true)
    {
        if ( freq[x] )
        {
            //cerr<<"! "<<x<<endl;
            rep = x; 
            break;
        }

        freq[x] = 1;

        sequence.pb(x);

        x*=x;
        x%=mod;
    }

    for ( auto it: sequence )
    {
        if ( it == rep )
            found = true;

        if ( found )
            cycle.push_back(it);

        else
            ++init;
    }  

    for (int i=1; i<sequence.size(); ++i)
        sequence[i]+=sequence[i-1];

    for (int i=1; i<cycle.size(); ++i)
        cycle[i]+=cycle[i-1];

    if ( n<=sequence.size() )
        ans = sequence[n-1];
    
    else
    {
        if (init)
        ans = sequence[init-1];
        n-=init;
        int fct = n / cycle.size();
        int rem = n%cycle.size();
       // cerr<<"! "<<fct<<" "<<rem<<" "<<cycle.back()<<endl;
        ans+=fct*cycle.back();
        if ( rem )
            ans+=cycle[rem-1];
    }

    cout<< ans <<endl;
}

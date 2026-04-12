#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf pop_front()
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define vll vector<lli>
#define stp setprecision(15)
#define eps 0.000001
#define endl '\n'
#define mod2 998244353
#define ll lli

using namespace std ;

#define N 200000+5 

typedef tree<lli,null_type,less<lli>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main() 
{
/////////////////////////////////////
    
    fastio;
 
/////////////////////////////////////    

    lli n;
    cin>>n;

    lli a[n];
    loopl(i,0,n) cin>>a[i];

    multiset<lli> s;
    s.insert(a[0]);

    loopl(i,1,n)
    {
        auto it = s.lb(a[i]);
        if(it == s.begin())
            s.insert(a[i]);

        else
        {
            it--;
            s.erase(it);
            s.insert(a[i]);
        }
    }

    cout<<s.size()<<endl;

}


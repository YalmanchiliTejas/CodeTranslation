#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define ll long long int
#define vr vector
#define pb push_back
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define loop(i,n) for(i=0;i<n;i++)
#define inp !cin.eof()
#define sec itr->second
#define fir itr->first

ll power(ll x,ll y,ll p)
{
    ll res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x)%p;

        // y must be even now
        y = y>>1; // y = y/2
        x = ((x%p)*(x%p))%p;  // Change x to x^2
    }
    return res%p;
}


int main()
{
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     // iterating a loop until input is providing====!cin.eof()
     //ll t; cin>>t;

     //scanf("%lld",&t);
     //while(t--)
        {

         ll n,m,q,i,x,y,p=1,z,j,k,flag=1,cnt=0,mi=mod,c=0,sum=0,ma=0,ans=0;
          vr<ll> v,v1,v2;


            cin>>n;
            if(n>=30)
                cout<<"Yes";
            else
                cout<<"No";

              cout<<endl;
          }


    return 0;

}


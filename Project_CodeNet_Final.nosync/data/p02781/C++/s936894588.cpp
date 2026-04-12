/*
  AUTHOR:SOURABH
  CREATED:09:02:20
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<ll , null_type, less< ll >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define W while
#define fn(i,x) for(i=0;i<x;i++)
#define fs(i,s,x) for(i=s;i<x;i++)
#define fr(i,x) for(i=x;i>=0;i--)
#define fit(it,s) for(it=s.begin();it!=s.end();it++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define mod 1000000007
#define MAX 100005
#define M 32

using namespace std;
using namespace __gnu_pbds;

ll C(ll n,ll k)
{
    if(n<k)
        return 0;
    ll num=1,den=1,p=n,q=k,i;
    fn(i,k)
    {
        num=num*p;
        p--;
        den=den*q;
        q--;
    }
    return num/den;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen(2 "out.txt","w",stdout);

    ll t,n,k,i,ans;
    string s;
    t=1;
    //cin>>t;
    W(t--)
    {
        cin>>s>>k;
        n=s.length();
        ans=0;
        fs(i,1,n)
        {
            ans+=(9*C(i-1,k-1))*(ll)(pow(9,k-1)+.5);
        }

        //cout<<ans<<endl;
        fs(i,1,n+1)
        {
            if(s[i-1]-'0'>=1)
            {
                ans+=(max(0,(s[i-1]-'0')-1)*C(n-i,k-1))*(ll)(pow(9,k-1)+.5);
                if(i>1)
                {
                    ans+=C(n-i,k)*(ll)(pow(9,k)+.5);
                }
                k--;
            }
            if(k==0)
            {ans+=1;break;}
        }
        cout<<ans<<"\n";
    }
    return 0;
}





























/*  TAHMID RAHMAN
    DAMIAN FOREVER
     MATH LOVER
    NEVER GIVE UP
*/
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define GCD(a,b) __gcd(a,b);
#define endl "\n"
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define INFLL 9223372036854775807
#define debug 0
#define MAXN   100001
#define ar array
const int mxN=2e5;
const int MOD=1e9+7;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
//Don't hesitate to ask me if you don't understand my code.......Happy coding,Tahmid...;

int main()
{
    fastio;
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {
        ll n,x,m,i,sum=0,temp,val=-1;
        cin>>n>>x>>m;
        sum+=x;
        vector<ll>v;
        set<ll>s;
        v.pb(x);
        s.in(x);
        bool ok=false;
        for(i=1;i<n;i++)
        {
            temp=v[i-1]%m;
            temp*=temp;
            temp%=m;
            if(temp==0)
                break;
            if(s.count(temp)==1)
            {
                ok=true;
                val=temp;
                break;
            }
           v.pb(temp);
           sum+=v[i];
           s.in(temp);
        }

        ll tot=0;
        vector<ll>copy;
        if(ok)
        {
            bool ok1=false;
            for(i=0;i<v.size();i++)
            {
                if(v[i]==val)
                {
                    ok1=true;
                    copy.pb(val);
                    tot+=val;
                }
                else if(ok1)
                {
                    copy.pb(v[i]);
                    tot+=v[i];
                }
            }
        }


//        cout<<v.size()<<" "<<sum<<" "<<copy.size()<<" "<<tot<<endl;

        if(debug)
        {
            for(auto x:v)
            {
                cout<<x<<" ";
            }
            cout<<endl;


            for(auto x:copy)
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }

        if(!ok)
        {
            cout<<sum<<endl;
            return 0;
        }


        ll left=n-v.size();
        ll summ=left/copy.size();
        summ*=tot;
        ll rem=left%copy.size();

        for(i=0;i<rem;i++)
        {
            summ+=copy[i];
        }

        cout<<sum+summ<<endl;



    }

}

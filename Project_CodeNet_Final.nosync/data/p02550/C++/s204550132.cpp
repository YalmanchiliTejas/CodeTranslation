using namespace std;
#include <bits/stdc++.h>
#define frr(i, r, l) for(int i = r; i >= l; --i)
#define fr(i, l, r) for(int i = l; i < r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define MEMS(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define m_p make_pair
#define pb push_back
#define ll long long
#define ld long double
typedef pair<ll, ll> iPair; 
priority_queue< ll, vector <ll> , greater<ll>>pq1,pq2;
#define maxN 1000000000000000000
ll power(ll a,ll b){ll res=1;while(b>0){res*=a;b--;}return res;}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,m,cnt[200005]={0},sum=0;
    vector<ll>v;
    cin>>n>>x>>m;
    v.pb(x);
    cnt[x]++;
    sum+=x;
    ll t=x,st,j=2;
    while(1)
    {
        if(j>n)
        {
            cout<<sum<<endl;
            return 0;
        }
        ll calc=(t*t)%m;
        if(cnt[calc]==0)
        {
            v.pb(calc);
            sum+=calc;
            cnt[calc]++;
        }
        else
        {
            fr(i,0,v.size())
            {
                if(v[i]==calc)
                {
                    st=i;
                    break;
                }
            }
            break;
        }
        j++;
        t=calc;
    }
    ll st1=n-v.size();
    ll st2=v.size()-st;

    ll tot=0;
    fr(i,st,v.size())
    tot+=v[i];

    sum=sum+(st1/st2)*tot;
    ll st3=st1%st2;

    fr(i,st,st+st3)
    sum+=v[i];

    cout<<sum<<endl;
    return 0;
}

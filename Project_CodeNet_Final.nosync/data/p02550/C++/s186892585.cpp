#include<bits/stdc++.h>
#define cases long long test;cin>>test;while(test--)
#define f_io ios::sync_with_stdio(false); cin.tie(0)
#define foi(a,n) for(long long i=a;i<n;i++)
#define foj(a,n) for(long long j=a;j<n;j++)
#define fok(a,n) for(long long k=a;k<n;k++)
#define ll long long
#define MOD 1000000007
#define INF 1000000000
using namespace std;

int main()
{
    f_io;
    ll n,x,m,ans=0;
    cin >> n >> x >> m;
    vector<ll> arr;
    map<ll,bool> mp;
    arr.push_back(x);
    mp[x]=1;
    ans+=x;
    foi(1,n)
    {
        ll tmp = (arr[i-1]*arr[i-1])%m;
        if(mp.count(tmp))
        {
            ll ind = find(arr.begin(),arr.end(),tmp)-arr.begin();
            //cout << i << " ";
            ll sz = i - ind;
            ll rem = n - i;
            ll sumi = 0LL;
            foj(ind,i)
                sumi+=arr[j];
            ans += (rem/sz)*sumi;
            rem%=sz;
            foj(0,rem)
                ans+=arr[ind+j];
            break;
        }
        else
        {
            ans+=tmp;
            arr.push_back(tmp);
            mp[tmp]=1;
        }
    }
    cout << ans;
    return 0;
}
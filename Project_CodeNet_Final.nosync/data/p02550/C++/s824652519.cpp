#include <bits/stdc++.h>
  
using namespace std;
 
#define endl "\n"
#define JAM(x) cout<< #x <<" = "<<x<<"\n"

 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPI;
 
const int INF=2e9;
const int MX=100005;
const int MOD=1000000007;
const double PI=acos(-1.0);



long long int power(long long int a,long long int b,long long m)
{
    a %= m;
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bool isprime(int n)
{
    if(n==1)
    return 0;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}




/*_______________________________________________*/





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,x,m,i;
    long long ans=0;
    cin>>n>>x>>m;
    map<long long ,int> mp;
    vector<long long> vec;
    for(i=0;i<n;i++)
    {
        if(mp.find(x)!=mp.end())
        break;
        mp[x]=i;
        ans+=x;
        vec.push_back(ans);
        x=power(x,2,m);
    }
    if(i>=n)
    cout<<ans;
    else
    {
        long long ind=mp[x];
        long long temp=vec[i-1];
        if(ind>0)
        temp-=vec[ind-1];
        long long temp1=(n-i)/(i-ind);
        ans+=temp1*temp;
        temp1=(n-i)%(i-ind);
        if(temp1)
        {
            ans+=vec[ind+temp1-1];
            if(ind>0)
            ans-=vec[ind-1];
        }
        cout<<ans;
    }
}

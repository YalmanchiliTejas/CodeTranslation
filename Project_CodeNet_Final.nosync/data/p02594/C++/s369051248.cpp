#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define fr(i,a,b) for(i=a;i<b;i++)
#define rfor(i,a,b) for(i=b-1;i>=a;i++)     // reverse loop
#define yes "YES"
#define no "NO"
#define srt(a) sort(a.begin(),a.end())
#define rsort(a) sort(a.rbegin(),a.rend())          // reverse sort

using namespace std;
const int mod = 1e9 + 7;
vector<ll>prime(1000001,1);
vector<ll>sdf(1000001,1);
long long inf=1000000000000000007;


vector<vector<int>>l;
vector<bool>visited;


/*

int isprime(ll n)
{
    ll i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
            {//cout<<i<<endl;
            return 0;}
    }
    return 1;
}
int isperfectsq(ll n)
{


    long double x;
    x=(long double)(sqrt((long double )(n)));
    ll y=sqrt(n);
    if(x==y)
        return 1;
        else
            return 0;
}
*/
//ll C[101][101];
/*void ncr()
{
    C[0][0] = 1;
    for (int n = 1; n <= 500000; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}
*/
/*
void sieve()
{
    //cout<<"in1";
    ll i;
    //sdf[i]=1;
    ll j;
    //for(i=1;i<=1000000;i++)
      //  sdf[i]=i;
    prime[0]=prime[1]=0;
    for(i=2;i<=1000000;i++)
    {
            if(prime[i]){
            //isprime.push_back(i);
            for(j=2*i;j<=1000000;j+=i)
            {
                prime[j]=0;
               // if(sdf[j]==j)
                 //   sdf[j]=i;
                 a[j]++;
            }
            }

    }

}
*/

ll maxi(ll a,ll b,ll c)
{
    ll m1=max(a,b);
    ll m2=max(a,c);
    return max(m1,m2);
}

long long modular_expo(long double x,long long y)
{

    if(y==0)
        return 1;
    if(y%2==0)
        return modular_expo(x*x,y/2);
    if(y%2==1)
        return x*modular_expo(x*x,(y-1)/2);


}
/*
void dfs(int t)
{
    int temp;
    visited[t]=true;
    //cout<<t<<" ";

        for(auto i=l[t].begin();i!=l[t].end();i++)
        {
            if(!visited[*i])
                dfs(*i);
        }

}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    if(t>=30)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }


}



////////////////////// bit masking ///////////
/*
ll total=long (pow(2,n));
    ll mask,j,cnt=0,ans=0,maxi,mini;
    for(mask=0;mask<total;mask++)
    {
        if(mask==0||mask==1||mask==2||mask==4||mask==8)
                continue;
        cnt=0;maxi=-1000000000000;mini=1000000000000;
        for(i=0;i<n;i++)
        {

            ll f=1<<i;
            if(mask&f)
            {
                maxi=max(maxi,a[i]);
                mini=min(mini,a[i]);
                cnt+=a[i];
            }
        }
        if(cnt>=l&&cnt<=r&&(maxi-mini>=x))
            ans++;


    }
    cout<<ans;
*/
///////////////////////////////////////////////////////

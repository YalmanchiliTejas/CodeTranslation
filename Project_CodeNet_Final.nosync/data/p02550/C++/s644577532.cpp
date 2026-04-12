                                      // Believe in yourself
#include<bits/stdc++.h>
#include<ctime>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Pair vector<pair<ll,ll>>
#define vec vector <ll> 
#define all(a) a.begin(),a.end()
#define mo 1000000007
#define decimal(i,n) fixed << setprecision(i) << n
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define show_nl(a) for(auto xyz:a)cout<<xyz<<endl;

//modular inverse
void eea(ll a,ll b,ll &x,ll &y)
{
    if (a == 1)
    {
        x = 1; y = 0;
        return;
    }
    ll x1, y1;
    eea(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
}
ll mi(ll a,ll m)
{
    ll x,y;
    eea(a,m,x,y);
    x= (x%m+m)%m;
    return x;
}
//complete

void Sieve(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
    {
        
    }       
}

/*
//segment tree
ll getMid(ll s, ll e) 
{ 
    return s + (e -s)/2; 
}
ll getSumUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll si)  
{  
    if (qs <= ss && qe >= se)  
        return st[si];  
    if (se < qs || ss > qe)  
        return 0;  
    ll mid = getMid(ss, se);  
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +  
        getSumUtil(st, mid+1, se, qs, qe, 2*si+2);  
}
void updateValueUtil(ll *st, ll ss, ll se, ll i, ll diff, ll si)  
{  
    if (i < ss || i > se)  
        return;  
    st[si] = st[si] + diff;  
    if (se != ss)  
    {  
        ll mid = getMid(ss, se);  
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);  
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);  
    }  
}
void updateValue(ll arr[], ll *st, ll n, ll i, ll val)  
{  
    if (i < 0 || i > n-1)  
    {  
        cout<<"Invalid Input";  
        return;  
    }  
    ll diff = val;  
    arr[i] = val+arr[i];  
    updateValueUtil(st, 0, n-1, i, diff, 0);  
}
ll getSum(ll *st, ll n, ll qs, ll qe)  
{  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        return -1;  
    }  
    return getSumUtil(st, 0, n-1, qs, qe, 0);  
} 
ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si)  
{  
    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
    ll mid = getMid(ss, se);  
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +  
            constructSTUtil(arr, mid+1, se, st, si*2+2);  
    return st[si];  
} 
ll *constructST(ll arr[], ll n)  
{  
    ll x = (int)(ceil(log2(n)));  
    ll max_size = 2*(int)pow(2, x) - 1;  
    ll *st = new ll[max_size];  
    constructSTUtil(arr, 0, n-1, st, 0);  
    return st;  
}
// completed
*/


int main()
{
    // clock_t time_req;
    // time_req = clock();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    ll t=1;
    // cin>>t;
    while(t--)
    {
       ll n,x,m;
       cin>>n>>x>>m;
       ll s=x,c=1,ans=s;
       ll a[m+1]={0};
       ll sum[m+1]={0};
       a[x]=1;
       sum[x]=x;
       while(n>c)
       {   
           ll r=s;
           s=(s*s)%m;
           ans+=s;
           c++;
           if(a[s]==0)
           {
           a[s]=c;
           sum[s]=ans;
           }
           else
           {
               ll p=c-a[s];
               ll ans1=ans-sum[s];
               ll fa=ans+(ans1)*((n-c)/p);
               n=n-c;
               c=1;
               while(n%p>=c)
               {   
                   s=(s*s)%m;
                   fa+=s;
                   c++;
               }
               ans=fa;
               break;
           }
           
           if(s==0)
           break;
       }
       cout<<ans<<"\n";
    }
    // time_req = clock()-time_req;
    // cout<<"Time taken: "<<(float)time_req/CLOCKS_PER_SEC<<"s"<<endl;
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/


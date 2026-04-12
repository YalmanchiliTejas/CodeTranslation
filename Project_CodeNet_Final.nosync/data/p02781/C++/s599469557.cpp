#include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

ll nxtl(){
    ll x;
    cin>>x;
    return x;
}
 
void SieveOfEratosthenes(int n,vector <int> &primes) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.push_back(p);
} 
 
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
 
ll power(ll x, ll y,ll mod) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,mod); 
    if (y%2 == 0) 
        return (temp*temp)%mod; 
    else
        return (((x*temp)%mod)*temp)%mod; 
} 
ll cal(ll len,ll k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    int k=nxt();
    ll test=0;
    for(int d=k;d<n;d++)
    {
        test+=(9*cal(d-1,k-1));
           //cout<<test<<endl;
    }
    vector <pair<int,int> > v;
    for(int i=0;i<n;i++)
        if(s[i]>48)
            v.push_back({s[i]-48,n-i-1});


    for(int i=0;i<k&&i<v.size();i++)
    {
        ll x=v[i].first;
        int j=0;
        if(i==0)
            j++;
        for(;j<x;j++){
            test+=cal(v[i].second,k-i-!!j);
            //cout<<j<<" "<<k-i-1<<" "<<v[i].second<<" "<<test<< endl;
        }
    }

    if(v.size()>=k)
        test++;
    cout<<test<<endl;


    return 0;   
}

ll cal(ll len,ll k)
{
    if(len<k)
        return 0;
    if(k==0)
        return 1;
    if(k==1)
        return 9*len;
    if(k==2)
    {
        ll ans=9*4*(len)*(len-1);
        ans+=9*(((len)*(len-1))/2);
        return ans;
    }
}


 
 

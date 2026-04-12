#include <bits/stdc++.h> 
using namespace std; 
#define in(x) int x; cin>>x;
#define sin(s) string s; cin>>s;
#define ll long long int 
#define lin(x) ll x; cin>>x;
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define pb push_back
#define re(i,n) for(ll i=0; i<n; i++)
#define pe(i,a,b) for(ll i=a; i<=b; i++)
#define rre(i,n) for(int i=n-1; i>-1; i--) 
#define mp make_pair
#define pii pair<ll,ll>
#define endl "\n"
#define pi 3.1415926536 
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define mod 1000000007
#define inf INT_MAX
/////////////////////////////////////////////////////////////////////////////////

bool compare(const pair<int, int>&i, const pair<int, int>&j) 
{ 
        if(i.second==j.second)
                return i.first>j.first;
        return i.second> j.second; 
} 
/////////////////////////////////////////////////////////////////////////////////
//vi v;
int ncr(int n, int k)   
{   
        if(n<k)
                return 0;
        int C[n + 1][k + 1];   
        int i, j;   
        for (i = 0; i <= n; i++)   
        {   
                for (j = 0; j <= min(i, k); j++)   
                {   
                        if (j == 0 || j == i)   
                                C[i][j] = 1;   
                        else  
                                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%mod;   
                }   
        }   
        return C[n][k];   
} 
////////////////////////////////////////////////////////////////////////////
ll modpowIter(ll a, ll b, ll c)   
{   
        int ans=1;  
        while(b != 0)   
        {  
                if(b%2 == 1) 
                ans=(ans*a)%c;  
                a=(a*a)%c;  
                b /= 2;   
        }  
        return ans;  
} 
///////////////////////////////////////////////////////////////////////////////
string intobin(int n)
{
        string s="";
        if(n==0)
                s="0";
        while(n)
        {
                if(n%2)
                        s="1"+s;
                else
                        s="0"+s;
                n/=2;
        }
        return s;
}

////////////////////////////////////////////////////////////////////////////////

int bintoin(string s)
{
        ll n=0;
        vll v;
        v.pb(1);
        re(i,400)
        {
                v.pb((v[v.size()-1]*2)%1000003);
        }
        rre(i,s.length())
        {
                n=(n+(s[i]-'0')*v[s.length()-i-1])%1000003;
                //cout<<v[s.length()-i-1]<<endl;
        }
        return n;
}
//////////////////////////////////////////////////////////////////////////////////
ll nc2(ll n, ll k)
{
        if(n<k)
                return 0;
        return (n*(n-1))/2;
}
///////////////////////////////////////////////////////////////////////////////////
bool prime[1000001]; 
void SieveOfEratosthenes(int n)   
{     
        memset(prime, true, sizeof(prime));   
        for (int p=2; p*p<=n; p++)   
        {    
                if (prime[p] == true)   
                {   
                        for (int i=p*p; i<=n; i += p)   
                        prime[i] = false;   
                }   
        }   
        /*for (int p=2; p<=n; p++)   
                if (prime[p])   
                        v.pb(p);  */
}   
////////////////////////////////////////////////////////////////////////////////////
int main()
{
        FAST
        in(n)
        if(n>=30)
                cout<<"Yes";
        else
                cout<<"No";
        return 0;
}
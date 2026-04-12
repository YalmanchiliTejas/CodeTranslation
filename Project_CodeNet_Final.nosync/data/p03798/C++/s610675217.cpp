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

string cal(string &s,char f,char s2,int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=nxt();
    string s;
    cin>>s;
    
    bool f=0;
    string x=cal(s,'W','W',n);
    if(x.length()==n)
    {
        cout<<x<<endl;
        return 0;
    }

    x=cal(s,'S','W',n);
    if(x.length()==n)
    {
        cout<<x<<endl;
        return 0;
    }

    x=cal(s,'W','S',n);
    if(x.length()==n)
    {
        cout<<x<<endl;
        return 0;
    }

    x=cal(s,'S','S',n);
    if(x.length()==n)
    {
        cout<<x<<endl;
        return 0;
    }

    cout<<"-1\n";

    
    
    
    return 0;   
}

string cal(string &s,char f,char s2,int n)
{
    string ret="";
    ret.push_back(f);
    ret.push_back(s2);
    for(int i=1;i<n-1;i++)
    {
        if(s[i]=='o'&&ret[i]=='S')
        {
            ret.push_back(ret[i-1]);
        }
        else if(s[i]=='o'&&ret[i]=='W')
        {
            if(ret[i-1]=='S')
                ret.push_back('W');
            else
                ret.push_back('S');
        }
        else if(s[i]=='x'&&ret[i]=='S')
        {
            if(ret[i-1]=='S')
                ret.push_back('W');
            else
                ret.push_back('S');
        }
        else if(s[i]=='x'&&ret[i]=='W')
        {
            ret.push_back(ret[i-1]);
        }
    }
    string temp="";
    bool f2=1;
    if(s[n-1]=='o'&&ret[n-1]=='S'&&ret[n-2]!=ret[0])
        {
            f2=0;
        }
        else if(s[n-1]=='o'&&ret[n-1]=='W'&&ret[n-2]==ret[0])
        {
             f2=0;
        }
        else if(s[n-1]=='x'&&ret[n-1]=='S'&&ret[n-2]==ret[0])
        {
             f2=0;
        }
        else if(s[n-1]=='x'&&ret[n-1]=='W'&&ret[n-2]!=ret[0])
        {
             f2=0;
        }

    if(s[0]=='o'&&ret[0]=='S'&&ret[n-1]!=ret[1])
        {
            f2=0;
        }
        else if(s[0]=='o'&&ret[0]=='W'&&ret[n-1]==ret[1])
        {
             f2=0;
        }
        else if(s[0]=='x'&&ret[0]=='S'&&ret[n-1]==ret[1])
        {
             f2=0;
        }
        else if(s[0]=='x'&&ret[0]=='W'&&ret[n-1]!=ret[1])
        {
             f2=0;
        }

        if(!f2)
            return temp;
        else
            return ret;


}




 
 

    //##################################################################################################
    //          ......................................................................................
    //         /  ............__........__.....__........__....__.....___...__...............______...   
    //        /  /           |  |      |  |   |  |      |  |  |  |   /  /  |  |             /      \        
    //       /  /            |  |      |  |   |  |      |  |  |  |  /  /   |  |            /   /\   \  
    //       \  \            |  |      |  |   |  |      |  |  |  | /  /    |  |           |   /  \   | 
    //        \  \......     |  |______|  |   |  |      |  |  |  |/  /     |  |           |  |    |  |    
    //         \......  \    |   ______   |   |  |      |  |  |     /      |  |           |  |____|  | 
    //                \  \   |  |      |  |   |  |      |  |  |     \      |  |           |   ____   | 
    //                /  /   |  |      |  |   |  \      /  |  |  |\  \     |  |           |  |    |  |       
    //.............../  /    |  |      |  |   \   \____/   /  |  | \  \    |  |_______    |  |    |  | 
    //................./     |__|      |__|    \__________/   |__|  \__\   |__________|   |__|    |__| 
    //##################################################################################################
     
    #include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back
    #define efr(i,a,b) for (long long i = a; i <= b; i++)
    #define ufr(i,a,b) for (long long i = a; i < b; i++)
    #define ub upper_bound
    #define lb lower_bound
    #define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
    #define mp make_pair
    #define ff first
    #define ss second
     
    typedef string str;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef double db;
    typedef pair<int,int> pii;
    typedef pair<ll,ll> pll;
    typedef vector<ll> vl;
    typedef vector<pll> vll;
    typedef vector<string> vs;
    typedef map<ll,ll> mll;
    typedef set<ll> sl;
     
    const ll N = 2e5 + 5;
    const db PI = acos(-1);
    const ll MOD = 1e9+7;
    const ll INF = 0x3f3f3f3f3f3f3f3f;
     
    ll fact(ll n)
    {
        ll ans=1;
        efr(i,1,n)
        {
            ans=ans*i;
        }
        return ans;
    }
     
    ll ncr(ll n,ll r)
    {
        return fact(n)/(fact(r)*fact(n-r));
    }
     
    bool isPrime(ll n) 
    { 
        if (n <= 1) 
            return false; 
     
        if (n <= 3) 
            return true; 
     
        if (n % 2 == 0 || n % 3 == 0) 
            return false; 
     
        for (ll i = 5; i * i <= n; i = i + 6) 
            if (n % i == 0 || n % (i + 2) == 0) 
                return false; 
      
        return true; 
    }
     
    bool isSorted(ll b, ll e,vl v)
    {
    	ll count=1;
    	ufr(i,b,e-1)
    	{
    		if(v[i]<=v[i+1])count++;
    	}
    	if(count==e-b)return true;
    	return false;
    }
     
    bool isVowel(char s){
    	if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return true;
    	return false;
    }
     
    bool isConsonant(char s){
    	if(!isVowel(s))return true;
    	return false;
    }
     
    ll lcm(ll a, ll b)  
    {  
       return (a*b)/__gcd(a, b);  
    }
    
    bool isDistinct(ll n)
    {
        ll a=0;
        set<ll> s;
        while(n!=0)
        {
            s.insert(n%10);
            n/=10;
            a++;
        }
        if(s.size()==a)return true;
        else return false;
    }

    void solve()
    {
        ll n,m;
        cin>>n>>m;
        if(n==m)cout<<"Yes";
        else cout<<"No";
    }
     
    int main() {
        fast
    
     
        ll t;
        t=1;
        //cin>>t;
        while(t--)
        {
            solve();
        }

    return 0;
    }
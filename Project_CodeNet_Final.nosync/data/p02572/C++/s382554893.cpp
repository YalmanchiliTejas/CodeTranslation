
#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define ld long double
#define mod 1000000007
#define big 1e18+10
#define small -big
#define pb push_back



template <typename T>

void prarr(T a)
{
     cerr << "[ ";
     
     for(auto i : a){
         cerr << i << " ";
     }
     
     cerr << "]" << endl;
}


#define trace(...) _er(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>

void _er(const char* name, Arg1&& arg1){
	cerr << "[" << name << " : " << arg1 << "]" << endl;
}

template <typename Arg1, typename... Args>

void _er(const char* names, Arg1&& arg1, Args&&... args){
    
	const char* comma = strchr(names + 1, ',');
	cerr << "[" ; cerr.write(names, comma - names) << " : " << arg1 << "] ";
	_er(comma+2, args...);
}



void solve() {
            
          ll n;
          cin >> n;
          
          ll sum = 0LL;
          ll ans = 0LL;
          for(ll i = 1; i <= n; i++) {
                    ll a;
                    cin >> a;
                    ll curr = (sum % mod) * (a % mod) % mod;
                    ans = (((ans % mod) + (curr % mod)) % mod);
                    sum += a;
          }
          
          cout << ans <<endl;
        
           
       
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   

    int t=1;
    //cin >> t;

    for(int i = 1; i <= t; i++) {  
   
         solve();
    }


    return 0;
        
}

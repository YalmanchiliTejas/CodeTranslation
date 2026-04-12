#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define ld long double
#define mod 998244353
#define big 1e18+100000000
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


map<ll, ll> g;

void solve() {
        
         ll n, x, m;
         cin >> n >> x >> m;
         
         if(n == 1) {
                cout << x << endl;
                return;
         }
         
         ll sum = 0;
         
         ll arr[m + 1] = {0};
         
         
         arr[1] = x;
         g[x] = 1;
         ll point = 0;
         ll loop = 0;
         
         for(ll i = 2; i <= m + 3; i++) {
                ll c = arr[i - 1];
                c *= c;
                c %= m;
                if(g[c]) {
                        loop = (i - g[c]);
                        point  = g[c];
                        break;
                }
                g[c] = i;
                arr[i] = c;
         }
         
         for(ll i = 1; i < point; i++) {
                sum += arr[i];
         }
         
         ll er = 0;
         
         for(ll i = point; i < (point + loop); i++) {
             er += arr[i];
         }
         
         n -= (point - 1);
         
         ll d = (n / loop);
         
         sum += (d * er);
         
         n %= loop;
         
         for(ll i = point; i < point + n; i++) {
                sum += arr[i];
         }
         
         cout << sum << endl;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    

    int t=1;
   // cin >> t;

    for(int i = 1; i <= t; i++) {  
   
         solve();
    }


    return 0;
        
}

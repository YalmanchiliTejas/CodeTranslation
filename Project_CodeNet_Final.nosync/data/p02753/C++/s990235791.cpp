#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <cstdlib>
#define sbc __builtin_popcount
#define pb push_back
#define em emplace
#define emb emplace_back
int mod = 1e9+7;
using namespace std;
// template<typename T>
	// T pwm(T a,T b)
    // {
        // T p=1,one=1;
        // while(b)
        // {
            // if(b&one) p=p*a%mod;
            // a=a*a%mod;
            // b >>=1;
        // }
        // return p;
    // }

    void solve() {
		string str;
		cin>>str;
		if(str[0]==str[1]&& str[1]==str[2])
		{
			cout<<"No\n";
		}
		else {
			cout<<"Yes\n";
		}
    }

int main()
{
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	
	
   // int t;
   // cin>>t;
   // while(t--)
	  solve();
  
	
    return 0;
}
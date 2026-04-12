#include <iostream>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef long long LL;
const int MAXN = 1e3+17;
int main(int argc ,char const *argv[])
{
    #ifdef noob
    freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    LL ans = 0;
    if(k==0) return cout<<1LL*n*n<<endl,0;
    for (int i = k+1; i <= n; ++i)
    {
    	int x = n/i;
    	if(i>k) 
    		ans += x*(i-k)+max(n%i-k+1,0);
    	// debug(i);
    	// debug(x);
    	// debug(ans);
    }
    cout<<ans<<endl;
    return 0;
}
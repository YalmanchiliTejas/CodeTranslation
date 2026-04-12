#include <iostream>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef long long LL;
const int MAXN = 1e4+17;
const int MOD = 1e9+17;
int main(int argc ,char const *argv[])
{
    #ifdef noob
    freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
    #endif
    string mp[10];
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
    	cin>>mp[i];
    }
    int x = 0,cnt=0;
    bool can = true;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		if(mp[i][j]=='#')
    			cnt++;
    	}
    }
    for (int i = 0; i < n; ++i)
    {
    	debug(x);
    	for (int j = x; j < m; ++j)
    	{
    		// debug(j);
    		// debug(mp[i][j]);
    		if(mp[i][j]!='#')
    		{
    			x = j-1;
    			break;
    		}
    		cnt--;
    		if(j==m-1)
    			x=j;
    	}
    }
    if(cnt==0) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;        
}
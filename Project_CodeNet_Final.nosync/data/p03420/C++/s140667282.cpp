#include <numeric>
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#include <sstream>
#include<string.h>
#include <cmath>
#include <iomanip>
using namespace std;
#define inf 1000000007
#define int long long
#define rep(i,j,n) for(int i=j;i<n;++i)
typedef pair<int,int>  P;
struct edge{int from,to,cost;};
double pi = 3.141592653589793;
//使うやつはここから下に置こうな
signed main(){
    int n,k;cin>>n>>k;
    int ans=0;
    if(k==0)cout<<n*n<<endl;
    else{
        rep(i,k+1,n+1){
            int h=0;
            ans+=n/i*(i-k)+max(n%i-k+1,h);
        }
        cout<<ans<<endl;
    }
    return 0;
}

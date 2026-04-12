#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#include<limits>
#include<bitset>
#include<ctype.h>
#include<set>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007LL;
const ll INF=1000000000;
const int MAX=100001;
const double EPS=1e-10;
int main(){
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int b=k+1;b<=n;b++){
        ans+=(n/b-1)*(b-k)+max(0,n%b-k+1);
        ans+=b-k;
        if(k==0){
            ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}

                           

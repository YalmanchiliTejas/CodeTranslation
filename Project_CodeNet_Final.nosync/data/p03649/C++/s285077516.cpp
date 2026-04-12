#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;


int main(void){
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll ans = 0;
    while(true){
        bool flag = true;
        int j=0;
        for(int i=0;i<n;i++){
            if(a[i]>=n){
                flag=false;
                ll num = a[i]/n;
                for(int j=0;j<n;j++){
                    if(j==i)a[i]-=num*n;
                    else a[j]+=num;
                }
                ans+=num;
            }
        }
        if(flag)break;
    }
    cout<<ans<<endl;
    return 0;
}
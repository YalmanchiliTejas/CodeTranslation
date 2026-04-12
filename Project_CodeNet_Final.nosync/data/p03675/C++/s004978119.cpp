#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define lowbit(x) (x&(-x))
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define MAX 100000000000000000
#define MOD 1000000007
#define pi acos(-1.0)
#define ei exp(1)
#define PI 3.141592653589793238462
#define INF 0x3f3f3f3f3f
#define mem(a) (memset(a,0,sizeof(a)))
typedef long long ll;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
const int N=200005;
const int mod=1e9+7;
int a[N];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        if(n&1){
            cout<<a[n];
            for(int i=n-2;i>=1;i-=2)
                cout<<" "<<a[i];
            for(int i=2;i<=n-1;i+=2)
                cout<<" "<<a[i];
            cout<<endl;
        }else{
            cout<<a[n];
            for(int i=n-2;i>=2;i-=2)
                cout<<" "<<a[i];
            for(int i=1;i<=n-1;i+=2)
                cout<<" "<<a[i];
            cout<<endl;
        }
    }
    return 0;
}

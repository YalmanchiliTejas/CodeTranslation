#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
const int N = 200002;
const int M = 1e9 + 7;
const int oo = INT_MAX;
int n;
ll a[N];

int main(){
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
        sum+=a[i];
    }
    sum%=M;
    ll ans=0;
    for(int i=0;i<n;i++){
        sum -= a[i];
        sum += M;
        sum %= M;
        ans += sum * a[i] ;
        ans %= M;
       
    }
    cout<<ans<<endl;
}


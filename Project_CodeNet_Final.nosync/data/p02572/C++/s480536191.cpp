#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
 
long long mod = 1000000007;
const long long N=2e5+10;

long long a[N];

long long sum=0;
int main() {
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum %= mod;
    
    long long ans=0;
    
    for(int i=1;i<=n;i++){
        sum-=a[i];
        if(sum<0)sum+=mod;
        ans+=(a[i] * sum);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}

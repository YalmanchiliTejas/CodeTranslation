#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
#define MOD 1000000007
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    LL ans=0;
    cin >> n;
    vector<LL> a(n);
    vector<LL> a_sum(n,0);

    for(LL i=0; i<n; i++){
        cin >> a[i];
    }

    a_sum[n-1]=a[n-1];
    for(LL i=n-2; i>=0; i--){
        a_sum[i]=(a_sum[i+1]+a[i])%MOD;
    }
    for(LL i=0; i<n-1; i++){
        ans=(ans+(a[i]*a_sum[i+1])%MOD)%MOD;
    }

    cout << ans << endl;

    return 0;
}

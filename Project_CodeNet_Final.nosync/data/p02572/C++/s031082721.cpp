#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using intl = int64_t;
using graph = vector<vector<int> >;
int main(){
    const intl m=1000000007;
    int n;
    cin >> n;
    intl a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    intl s[n-1];
    s[0]=a[0]%m;
    for(int i=1;i<n-1;i++){
        s[i]= (s[i-1]+a[i])%m; 
    }

    intl sum=0;
    for(int i=0;i<n-1;i++){
        sum += (s[i]*a[i+1])%m;
    }

    cout << sum%m << endl;
}
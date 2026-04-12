#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    long long sum = 0;
    int A[n];
    int mod = 1000000007; 
    long long ans = 0;
    for(int i = 0;i<n;i++){
    	cin>>A[i];
        sum += A[i];
        sum %= mod;
    }
    for(int i = 0;i<n;i++){
        sum -= A[i];
        if (sum < 0) sum += mod;
    	ans += sum*A[i];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
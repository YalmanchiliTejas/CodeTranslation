#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
    
    
using namespace std;
     
int main() {
	long long n;
	cin >> n;
	long long sum = 0;
	long long ans = 0;	
	vector<int> A(n);
	int mod = 1000000007;
	for(int i = 0; i < n; ++i){
		cin >> A[i];
		sum += A[i];
		sum %= mod;
		}	
		
	    for (int i = 0; i < n; i++)
    {
		
        sum -= A[i];
        if (sum < 0) sum += mod;
 
        ans += A[i] * sum;
        ans %= mod;
    }
		
	cout << ans<< endl;
	return 0;
}

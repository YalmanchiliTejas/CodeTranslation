#include <bits/stdc++.h>
using namespace std;
vector<int> sprime(int n) 
{ 
    
    bool prime[n+1]; vector<int>v;
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
      { if (prime[p]) 
          {
              v.push_back(p);
          }
      }
      return v;
} 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x;cin>>x;
	if(x>=30)
	cout<<"Yes"<<"\n";
	else
	cout<<"No"<<"\n";
	  
	return 0;
}

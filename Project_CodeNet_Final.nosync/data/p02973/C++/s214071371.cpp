#include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

ll nxtl(){
    ll x;
    cin>>x;
    return x;
}
 
void SieveOfEratosthenes(int n,vector <int> &primes) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
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
       if (prime[p]) 
          primes.push_back(p);
} 
 
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
 
ll power(ll x, ll y,ll mod) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,mod); 
    if (y%2 == 0) 
        return (temp*temp)%mod; 
    else
        return (((x*temp)%mod)*temp)%mod; 
}

int MinimumNumIncreasingSubsequences(vector <int> arr, int n) 
{ 
    multiset<int> last; 
  
    // last element in each  increasing subsequence  
    // found so far 
    for (int i = 0; i < n; i++) { 
  
        // here our current element is arr[i] 
        multiset<int>::iterator it = last.lower_bound(arr[i]); 
  
        // iterator to the first element larger  
        // than or equal to arr[i] 
        if (it == last.begin()) 
  
            // if all the elements in last larger 
            // than or to arr[i] then insert it into last 
            last.insert(arr[i]); 
  
        else { 
            it--; 
  
            // the largest element smaller than arr[i] is the number 
            // before *it which is it-- 
            last.erase(it); // erase the largest element smaller than arr[i] 
            last.insert(arr[i]); // and replace it with arr[i] 
        } 
    } 
    return last.size(); // our answer is the size of last 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=nxt();
    vector <int> v(n);
    generate(all(v),nxt);
    cout<<MinimumNumIncreasingSubsequences(v,n)<<endl;
    
    
    
    return 0;   
}


 
 

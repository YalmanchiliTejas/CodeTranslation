#include <bits/stdc++.h> 
using namespace std; 
#include <stack>
#define ll long long 
const ll INF=1000000007;
#define vecpair vector<pair <ll,ll> >
#define pb push_back
#define mp make_pair
#define vel vector<ll>
bool prime[100001];
void SieveOfEratosthenes() 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true.  
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=100000; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=100000; i += p) 
                prime[i] = false; 
        } 
    } 
  
    
} 
ll bs(vel a,ll s,ll e,ll x){
	int l=s;
	int h=e;
	int m;
	while(l<=h){
		m=(l+h)/2;
		if(a[m]>x) h=m-1;
		else if(a[m]<x) l=m+1;
		else return m;
		}
		return -1;
	}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
SieveOfEratosthenes();
ll test;
test=1;
while(test--){
int x;
cin>>x;
if(x>=30) cout<<"Yes";
else cout<<"No";
}
}

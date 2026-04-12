#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define pb push_back
bool isPrime(ll n) 
{ 
    
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
   
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
ll minthis(ll a, ll b){
if(a < b){
return a;
}
return b;
}
ll maxthis(ll a, ll b){
if(a > b){
return a;
}
return b;
}
int gcd(int a, int b){
    if( a<0 ) a = -a;
    if( b<0 ) b = -b;
    while( b!=0 ){
        a %= b;
        if( a==0 ) return b;
        b %= a;
    }
    return a;
}
 
int findLargestDivisor(int n) 
{ 
	int max = 1;
    for (int i = 2; i < n; i++) {        
        if(n %(i) == 0) { 
            max = i;
        } 
    }
    return max;     
} 
	 
 
ll power(ll x, ll y)  
{  
    ll temp;  
    if(y == 0)  
        return 1;  
    temp = power(x, y / 2);  
    if (y % 2 == 0)  
        return (temp * temp)%1000000007;  
    else
    {  
        if(y > 0)  
            return (x * temp * temp)%1000000007;  
        else
            return (temp * temp)%1000000007 / x;  
    }  
} 
bool sortbysec(const pair<int, int>& a, 
               const pair<int, int>& b) 
{ 
    return (a.second < b.second); 

} 


void solve(){
    int n;
    cin >> n;
    if(n >= 30) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}
int main(){ 
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
	solve();
    }
    return 0; 
}




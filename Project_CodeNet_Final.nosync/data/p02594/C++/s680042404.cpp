#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pci pair<char,int
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mci map<char,int>
#define umii unordered_map<int,int>
#define umll unordered_map<long long int,long long int>
#define umci unordered_map<char,int>
#define F first
#define S second
#define pb push_back
#define endl '\n'
#define mod 1000000007
using namespace std;
#define maxval 10003000

bool sortinrev(const pair<ll,ll> &a,  
               const pair<ll,ll> &b) 
{
       if(a.first!=b.first) return(a.first > b.first);
       else return (a.second<b.second);
} 
ll power(ll x,ll n)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x);
        x=(x*x);
        n=n/2;
    }
    return result;
}
bool isPrime(ll k){
    if(k<=1){return false;}
    if(k==2){return true;}
    if(k%2==0){return false;}
    ll i = 3;
   while (i*i <= k) {if (k % i == 0) {return false;}i += 2;}
return true;
}


int main(){
   IOS;
ll t;t=1;//cin>>t;
while(t--){
ll n;cin>>n;
if(n>=30) cout<<"Yes\n";
else cout<<"No\n";

}


    
    
    
    





return 0;}
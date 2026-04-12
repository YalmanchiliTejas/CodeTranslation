#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
ll sieve[1000001]={0},i,j;
ll power(ll p, ll k)
{
ll a=1;
while(k)
{
if(k&1)
a=(a*p);
p=(p*p);
k>>=1;
}
return a;
}
using namespace std;
  ll countDivisors(ll n) 
{ 
    ll cnt = 0; 
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
  
            else 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int tc=1;
//cin>>tc;
ll cas=1;
 while(tc--)
 {
	string s;
	cin>>s;
	if(s!="AAA" && s!="BBB")
	cout<<"Yes";
	else
	cout<<"No";
	cout<<"\n"; 
 } 
}

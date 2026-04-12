#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using vi = vector<int>;
using vl= vector<ll>;
using vs=vector<string>;

ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a);}
ll max(ll a, ll b) {if (a > b) return a; else return b;}
ll min(ll a, ll b) {if (a < b) return a; else return b;}
ll power(ll a,ll b) {ll i,p=1; for(i=0;i<b;i++){p*=a;} return p;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
	string s;
	cin>>s;
	ll counter=0;
	for(int i=0;i+1<s.size();i++){
if((s[i]=='A' && s[i+1]=='B')||(s[i]=='B' && s[i+1]=='A'))
counter++;
}
if(counter!=0)
cout<<"Yes";
else
cout<<"No";


        }

    return 0;
}

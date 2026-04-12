#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}/*char to int*/
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}/*MAX*/
int lcm(ll a,ll b){return a*b/gcd(a,b);}/*MIN*/
bool primecheck(ll n){/*sosuu*/if(n < 2) return false;else{for(int i = 2; i * i <= n; i++){if(n % i == 0) return false;}return true;}}
string  reverserange(string s,ll a,ll b){reverse(s.begin()+a-1,s.begin()+b); return s;}
int  main(){
int n,m;
cin >> n >> m;
if(n==m){
    cout <<"Yes"<<endl;
    return 0;
}
cout << "No"<<endl;
}




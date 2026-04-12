#include<bits/stdc++.h>
#include <cmath>
#define ll long long  
#define PI 3.14159265358979323846
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb emplace_back
#define watch5(a,b,c,d,e) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d << " | "<<#e<<": "<<e<<endl;
#define watch4(a,b,c,d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define watch3(a,b,c) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<endl;
#define watch2(a,b) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<< endl;
#define watch(a) cerr <<#a<<": "<<a<<endl;
#define F first
#define S second
#define mod 1000000007
using namespace std;

int min(int a, int b){
  return a<b?a:b;
}

int32_t main(){
	IOS;
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = 0, sum = 0;
  int b[n];
  for(int i = n-1; i >= 0; i--){
    sum = ((sum % mod) + (a[i] % mod)) % mod;
    b[i] = sum;
  }
  for(int i = 0; i < n-1; i++){
    ans = (((ans % mod) + (((a[i] % mod) *1LL* (b[i+1] % mod)) % mod)) % mod);
  }
  cout << ans;
}																				  
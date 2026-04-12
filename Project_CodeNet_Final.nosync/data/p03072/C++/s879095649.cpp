#include<bits/stdc++.h>

using namespace std ;

#define IOS ios::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define ll long long int 

#define fr first
#define se second

#define all(v) v.begin(),v.end() 
#define rall(v) v.rbegin(),v.rend()
#define sz(v) v.size() 

#define pb push_back
#define mp make_pair 

#define PI 3.141592653589793238



ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b / gcd(a,b) ;}


//bool valid(int x, int y){return x > 0 && x < 9 && y > 0 && y < 9;}


int n, x, cntr;

int main(){
  cin >> n;
  cin >> x;
  cntr++;
  n--;
  while(n--){
    int c;
    cin >> c;
    if(c >= x){
      cntr++;
      x = c;
    }
  }
  cout << cntr;
  return 0;
}

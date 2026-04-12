#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <cmath>
#include <map> 
#include <sstream>
using namespace std;
 
const int MAX= 10000100;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()
#define ll long long int
#define gcd(a,b) __gcd(a,b)

int GCD(int a, int b) {if(!b) return a; return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}

int main(void){
 ll n,m;
  while(cin>>n>>m,n+m){
    vector<ll> tl(n+m);
    rep(i,n+m){
      cin>>tl[i];
    }
    sort(tl.begin(),tl.end());
    ll maxx = tl[0];
    rep(i,n+m-1){
      maxx = max(maxx,tl[i+1] - tl[i]);
    }
    cout<<maxx<<endl;
  }
  

}
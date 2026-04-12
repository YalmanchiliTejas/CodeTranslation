#include<iostream>
#include<iomanip>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
#include<tuple>
#include<numeric>
#include<map>
#include<cmath>
#define ll long long
#define rep(i,n) for(int i=0;i<(int) (n);i++)
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
using namespace std;
int main(){
  string s;
  cin>>s;
  int f=0;
  rep(i,2){
    if(s.at(i)!=s.at(i+1))f=1;
  }

  if(f==1)cout<<"Yes";
  else cout<<"No";
}

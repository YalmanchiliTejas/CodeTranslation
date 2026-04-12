#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
 
#define ll long long
 
#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));
 
int main(){
	ll N;
  cin >> N;
  vector<ll> p(N);
  ll sum = 0,t = 0;
  froop1(0,N){
    cin >> p.at(i);
    t = t + p.at(i);
    if(i != 0) sum += ((t - p.at(i))%1000000007LL)*p.at(i);
    sum %= 1000000007LL;
  }
  cout << sum << endl;
    
return 0;
}
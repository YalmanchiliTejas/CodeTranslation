#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;
void chmin(long long &a, long long b) { if (a > b) a = b; }

int main(){
  ll i, j;
  ll n;
  cin >> n;
  if(n == 3 || n == 5 || n == 7) 
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
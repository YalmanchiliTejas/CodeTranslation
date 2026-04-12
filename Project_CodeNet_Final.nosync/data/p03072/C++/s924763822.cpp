#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll h;
  ll s=0;
  ll l=0;
  for(int i=0;i<n;i++){
    cin >> h;
    if(l<=h)s++;
    l=max(l,h);
  }
  cout << s << endl;

}
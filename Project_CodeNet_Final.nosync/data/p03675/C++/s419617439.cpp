#include <bits/stdc++.h>
#define r(i,n) for(long long i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n,0);
  r(i,n)cin >> v[i];
  if(n==1)cout << v[0]<<endl;
  else if(n%2==0){
    r(i,n/2)cout << v[n-1-2*i]<<" ";
    r(i,n/2-1)cout << v[2*i]<<" ";
    cout << v[n-2];
  }
  else{
    r(i,n/2+1)cout << v[n-1-2*i]<<" ";
    r(i,n/2-1)cout << v[2*i+1]<<" ";
    cout << v[n-2];
  }
  cout << endl;
}

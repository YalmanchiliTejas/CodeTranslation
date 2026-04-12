// A

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

int main(){
  int x;
  cin>>x;
  if (x == 3 || x == 5 || x == 7){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}

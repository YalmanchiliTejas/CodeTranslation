#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

deque<int> d;

int main(){
int n; cin >> n;
  for(int i=0;i<n;i++){
    int a; cin >> a;
    if( i&1 ) d.push_back( a );
    else d.push_front( a );
  }
  if( n &1 )
    for(int i=0;i<n;i++){
      if( i ) cout << " ";
      cout << d[i];
    }
  else
    for(int i=n-1;i>-1;i--){
      if( i < n-1 ) cout << " ";
      cout << d[i];
    }
 cout << endl;
}
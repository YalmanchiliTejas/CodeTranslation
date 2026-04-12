#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

P A[200005];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  for(int i=0;i<n;i++) {
    int a; cin >> a;
    A[i] = P( a, i );    
  }
  int res[200005];
  sort(A,A+n);
  for(int i=0;i<n;i++){
    if( i < n/2 )
      res[A[i].second] = A[n/2].first;
    else
      res[A[i].second] = A[n/2-1].first;
  }
  for(int i=0;i<n;i++)
    cout << res[i] << endl;
}

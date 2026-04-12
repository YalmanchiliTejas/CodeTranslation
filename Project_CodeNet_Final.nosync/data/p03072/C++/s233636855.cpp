#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define PYES cout << "Yes" << endl
#define PNO cout << "No" << endl

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    bool ok=true;
    for(int j=0;j<i;j++){
      if(a[i]<a[j]){
        ok=false;
        break;
      }
    }
    if(ok) ans++;
  }
  cout << ans << endl;
  return 0;
}

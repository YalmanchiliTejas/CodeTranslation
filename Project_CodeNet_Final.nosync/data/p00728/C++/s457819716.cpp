#include <bits/stdc++.h>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;

int main(){
  while(true){
    int n; cin >> n;
    if(n ==0) break;
    vector<int> a(n); cinf(n,a);
    sort(a.begin(),a.end());
    int sum=0;
    for(int i=1;i<n-1;i++)
      sum +=a[i];
    cout << sum/(n-2) << endl;
  }
}

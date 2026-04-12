#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
  int n,i,a[100010];
  vector<int> l;
  vector<int>::iterator ite;
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  for (i=n-1;i>=0;i--){
    ite=lower_bound(l.begin(),l.end(),a[i]+1);
    if (ite==l.end()) l.push_back(a[i]);
    else *ite=a[i];
  }
  cout << l.size() << endl;
  return 0;
}
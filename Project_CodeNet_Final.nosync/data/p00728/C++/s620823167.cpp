#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  for(;;){
    int n;
    cin >> n;
    if(n==0) break;
    vector<int> v(n);
    for(int i=0; i<n; i++){
      cin >> v[i];
    }
    sort(v.begin(),v.end());
    int ret = 0;
    for(int i=1; i<v.size()-1; i++){
      ret += v[i];
    }
    ret /= n-2;
    cout << ret << endl;
  }
  return 0;
}
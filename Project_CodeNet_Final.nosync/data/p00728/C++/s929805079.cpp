#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

  int n;
  while(cin >> n,n){
    vector<int>v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=1;i<n-1;i++)ans += v[i];
    cout << ans/(n-2) << endl;
  }
  return 0;
}
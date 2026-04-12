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
    int sum=0;
    for(int i=1;i<n-1;i++)sum+=v[i];
    cout << sum/(n-2) << endl;
  }

  return 0;
}
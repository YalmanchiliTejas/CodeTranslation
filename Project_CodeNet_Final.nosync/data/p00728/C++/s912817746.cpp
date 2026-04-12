#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,a;
  vector <int> v;
  while(cin >> n,n){
    for(int i = 0;i < n;i++){
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(),v.end());
    int sum = 0;
    for(int i = 1;i < n-1;i++){
      sum += v[i];
    }
    sum = sum / (n-2);
    cout << sum  << endl;
    for(int i = 0;i < n;i++){
      v.pop_back();
    }
  }

}
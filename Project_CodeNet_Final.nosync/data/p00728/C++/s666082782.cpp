#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  while(1){
    int n;
    cin >> n;
    if(n==0)break;
    vector<int> a;
    for(int i=0;i<n;i++){
      int input;
      cin >> input;
      a.push_back(input);
    }
    sort(a.begin(),a.end());
    int sum=0;
    for(int i=1;i<a.size()-1;i++){
      sum+=a[i];
    }
    cout << sum/(n-2) << endl;
  }
}

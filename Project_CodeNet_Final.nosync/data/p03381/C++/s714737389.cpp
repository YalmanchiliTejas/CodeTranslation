#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    b[i]=a[i];
  }
  sort(a.begin(),a.end());
  int median=a[n/2-1];
  int hitotudekai=a[n/2];
  for(int i=0;i<n;i++){
    if(b[i]<=median){
      cout << hitotudekai << endl;
    }else{
      cout << median << endl;
    }
  }

  return 0;
}

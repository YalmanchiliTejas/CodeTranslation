#include <iostream>
#include <vector>
using namespace std;

int i,j,n;
string str;

int main(){
  cin >> n;
  vector<int> a(n),b(n);
  for(i = 0;i < n;i++) cin >> a[i];
  int s = 0,e = n-1;
  for(i = 0;i < n;i++){
    int index = n-1-i;
    if(i%2){
      b[e] = a[index];
      e--;
    }
    else{
      b[s] = a[index];
      s++;
    }
  }
  for(i = 0;i < n;i++){
    cout << b[i] << ' ';
  }cout << endl;
}

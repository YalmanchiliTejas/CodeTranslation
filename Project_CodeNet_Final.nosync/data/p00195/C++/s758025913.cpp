#include <iostream>
using namespace std;

int main() {
  int a,b;
  while(cin >> a >> b && (a!=0 || b!=0)) {
    int sum,max,ans=0;
    sum=max=a+b;
    for(int i=1; i<5; i++) {
      cin >> a >> b;
      sum=a+b;
      if(sum>max) {
	max=sum;
	ans=i;
      }
    }
    cout << (char)('A'+ans) << " " << max << endl;
  }
  return 0;
}

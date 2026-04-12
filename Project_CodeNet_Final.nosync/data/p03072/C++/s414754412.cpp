#include <iostream>

using namespace std;

int main(){
  int n,l,i;
  cin >> n;
  
  int a[n];
  
  for(i =0; i<n;i++){
    cin >> l;
    a[i] = l;
  }
  
  int count=0;
  int max =0;
  
  for(i=0;i<n;i++){
    for(int j=0;j<=i;j++){
		if(a[j] >= max){
          max = a[j];
        }
      
        if(i == j && max <= a[j]){
          count++;
          //cout << "in:" << a[j] << ":max:" << max << endl;
        }
    }
    max = 0;
  }
  cout << count <<endl;
  return 0;
}
    
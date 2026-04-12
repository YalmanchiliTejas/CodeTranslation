#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  
  int a[N];
  for(int i=0;i<N;i++){
	cin >> a[i];
  }
  
  int count=1;
  bool c = true;

  for(int i=1;i<N;i++){
	  for(int j=0;j<i;j++){
      if(a[i] < a[j]){
        c = false;
        break;
      }
    }
	  if(c == true){
		  count++;
    }
    c = true;
  }
  
  cout << count << endl;
  return 0;
}
#include <iostream>
using namespace std;
 
int main(){
  int N;cin >> N;
  int a[3]={7,5,3};
  for(int i=0;i<3;i++){
    if(a[i]==N){
      puts("YES");
      return 0;
    }
  }
	puts("NO");
  return 0;
}
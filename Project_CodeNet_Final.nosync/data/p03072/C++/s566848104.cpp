#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;

  int H[N];
  for(int i=0; i<N ; i++){
    cin >> H[i]; 
  }
  int nm=1;
  for(int j=1; j<N ; j++){ 
    int flag =1;
    for(int i=0; i<j ; i++){
      if(H[j] < H[i]){
	flag = 0;
	//	cout << H[j] << " " << H[i] << endl;
      }
    }
    if (flag==1){
      nm +=1;
    }
  }

  cout << nm << endl;

}

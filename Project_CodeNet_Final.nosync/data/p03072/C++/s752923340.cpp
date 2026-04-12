#include <iostream>

using namespace std;

  int check(int front, int back){
    int point = 0;
    if(front <= back){
      point++;
    }
    return point;
  }


int main(){
  int n;
  int counter = 1;
  cin >> n;
  if(n > 0 && n <= 20){
    int h[n];
    for(int i = 0; i < n; i++){
      cin >> h[i];
    }
    
    for(int i = 1; i < n; i++){
      //山の高さを比べる(再帰処理が必要)
      int j = i;
      int counter2 = 0;
      while(j > 0){
        counter2 += check(h[j-1], h[i]);
        //        cout << "counter2: " << counter2 << endl;
        j--;
      }
      if(counter2 == i){
        counter++;
      }
      //      cout << "counter: " << counter <<endl;
    }
    cout << counter << endl;
  }else{
    return 0;
  }
}


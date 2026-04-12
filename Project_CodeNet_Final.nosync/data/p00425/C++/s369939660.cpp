#include <iostream>
#include <vector>
using namespace std;

int dice[7];
void turn(int i, int j, int k, int l){
  int tmp=dice[l];
  dice[l]=dice[k];
  dice[k]=dice[j];
  dice[j]=dice[i];
  dice[i]=tmp;
}

int main(){
  while(1){
    int n;
    cin >> n;
    if(n==0) break;

    for(int i=1; i<=6; i++) dice[i]=i;
    int sum=1;
    for(int i=0; i<n; i++){
      string str;
      cin >> str;
      if(str=="North") turn(1,5,6,2);
      if(str=="East") turn(1,3,6,4);
      if(str=="West") turn(1,4,6,3);
      if(str=="South") turn(1,2,6,5);
      if(str=="Right") turn(2,4,5,3);
      if(str=="Left") turn(2,3,5,4);
      sum += dice[1];
    }
    cout << sum << endl;
  }
  return 0;
}
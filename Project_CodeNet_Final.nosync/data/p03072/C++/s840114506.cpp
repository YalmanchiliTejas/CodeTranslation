#include<iostream>
using namespace std;

int main(void){
  int n;
  cin >> n;
  int buf[n];
  for(int i = 0;i < n; i++)
    scanf("%d", &buf[i]);

  
  int height = buf[0];
  int num = 1;
  for(int i=1;i<n;i++){
    if(height <= buf[i]){
      height = buf[i];
      num +=1;
    }   
  }
  cout << num <<endl;
  return 0;
}

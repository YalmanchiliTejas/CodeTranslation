#include <iostream>

using namespace std;

int main(){

int n;
  cin >> n;
int h;
int height=0,counts=0;
  
  for(int i=0;i<n;i++){
   cin >> h;
    
    if(h>=height){
     counts++;
    }
    
   height=max(height,h);
  }
  cout << counts; 
}

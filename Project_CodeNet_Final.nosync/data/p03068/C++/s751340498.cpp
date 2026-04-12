#include <iostream>
#include <string>
using namespace std;
 
int main(void){
  int n;
  cin >> n;
  
  string word;
  cin >> word;
  
  int k;
  cin >> k;
  
  char p = word[k-1];
  for(int i=0;i<n;i++){
    if(word[i] != p){
      word[i] = '*';
    }
  }
    cout << word << endl;
    
    return 0;
}
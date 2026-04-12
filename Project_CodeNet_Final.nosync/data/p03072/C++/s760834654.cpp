#include <iostream>
#include <vector>
using namespace std;

int main() {
  int latas_seged=1;
  int n;
  bool logikai_valtozo=true;
  vector <int> sanyiszamok;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> latas_seged;
    sanyiszamok.push_back(latas_seged);
  }
  latas_seged=1;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(sanyiszamok[j]>sanyiszamok[i]){
        logikai_valtozo=false;        
      }
    }
    if(logikai_valtozo){
     latas_seged+=1; 
    }
    logikai_valtozo=true;
  }
  cout << latas_seged;
	return 0;
}

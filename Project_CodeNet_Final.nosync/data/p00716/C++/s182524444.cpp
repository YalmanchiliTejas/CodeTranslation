#include <iostream>

using namespace std;

int main(){
  int m;
  unsigned long long int money;
  unsigned long long int initial;
  unsigned long long int max;
  unsigned long long int risi;
  unsigned int nensu;
  unsigned int n;
  int fukuri;
  double nenri;
  unsigned long long int tesuryo;
  
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> initial;
    cin >> nensu;
    cin >> n;
    max = 0;
    for(unsigned int j=0; j<n; j++){
      money = initial;
      risi = 0;
      cin >> fukuri >> nenri >> tesuryo;
      if(fukuri){
	for(unsigned int k=0; k<nensu; k++){
	  risi = money * nenri;
	  money = money + risi - tesuryo;
	}
      }else{
	for(unsigned int k=0; k<nensu; k++){
	  risi += money * nenri;
	  money += -tesuryo;
	}
	money += risi;
      }
      if(max < money){
	max = money;
      }
    }
    cout << max << endl;
  }

  return 0;
}
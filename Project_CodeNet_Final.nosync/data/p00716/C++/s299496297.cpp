#include <iostream>
#include <vector>
using namespace std;

int tanri(int, int, double, int);
int fukuri(int, int, double, int);

int main(){
  int m;

  cin >> m;

  for(int i=0;i<m;i++){
    int fund,years,n;
    cin >> fund >> years >> n;

    int max=0;

    for(int j=0;j<n;j++){
      int kind;
      double nenri;
      int tesuuryou;
      cin >> kind >> nenri >> tesuuryou;
      if(kind==0){
        if(max<tanri(years,fund,nenri,tesuuryou)) max = tanri(years,fund,nenri,tesuuryou);
      }else if(kind==1){
        if(max<fukuri(years,fund,nenri,tesuuryou))max = fukuri(years,fund,nenri,tesuuryou);
      }
    }
    cout << max << endl;
  }

  return 0;
}

int tanri(int years, int fund, double nenri, int tesuuryou){
  int ans=0;
  int rishi = 0;
  for(int i=0;i<years;i++){
    rishi += fund * nenri;
    fund -= tesuuryou;  
  }
  return ans = rishi + fund;
}

int fukuri(int years, int fund, double nenri, int tesuuryou){
  int ans=0;
  int rishi=0; 
  for(int i=0;i<years;i++){
    rishi = fund * nenri;
    fund += rishi - tesuuryou;
  }

  return ans = fund;
}
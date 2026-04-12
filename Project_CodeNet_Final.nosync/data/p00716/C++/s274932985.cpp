#include "algorithm"
#include "iostream"

using namespace std;

int main(){
  int m,n,A,B,B_sum,now,minas,year,FLAG;
  double rate;
  cin >> m;

  while(m--){
    int LAST_MAX=0;
      cin >> now >> year >> n;
      for(int i=0;i<n;++i){
      A=now;
      B=0;
      B_sum=0;
      cin >> FLAG >> rate >> minas;
      for(int j=0;j<year;++j){
        B=A*rate;
        if(FLAG&1)A+=B-minas;
        else{
          A-=minas;
          B_sum+=B;
        }
      }
      if(FLAG&1)LAST_MAX=max(A,LAST_MAX);
      else LAST_MAX=max(A+B_sum,LAST_MAX);
    }
    cout << LAST_MAX <<endl;
  }
  return 0;
}
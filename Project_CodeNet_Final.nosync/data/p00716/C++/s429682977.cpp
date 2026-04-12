#include <iostream>
#include <vector>
using namespace std;

struct Operation{
  bool op;
  double interest;
  int charge;
};

int main(){
  int m;
  cin >> m;
  while(m--){
    int value, y, n;
    vector<Operation> ope;
    
    cin >> value >> y >> n;
    
    Operation tmp;
    
    for(int i = 0 ; i < n ; i++){
      cin >> tmp.op >> tmp.interest >> tmp.charge;
      ope.push_back(tmp);
    }
    
    int ans = -1;
    
    for(int i = 0 ; i < n ; i++){
      int t = value;
      if(ope[i].op == 0){
	int v = 0;
	for(int j = 0 ; j < y ; j++){
	  v += t*ope[i].interest;
	  t -= ope[i].charge;
	}
	ans = max(ans, v+t);
      }
      else{
	for(int j = 0 ; j < y ; j++){
	  t += t*ope[i].interest;
	  t -= ope[i].charge;
	}
	ans = max(ans, t);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
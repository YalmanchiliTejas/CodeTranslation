#include<iostream>
#include<vector>
using namespace std;

int main(){
  long a,b,c,x,y;
  
  long an,bm,cl;
  long min = 9999999999999;
  long cost1,cost2,cost3;
  vector<long> cost;
  cost.resize(3);
  cin >> a >> b >> c >> x >> y;

  // 1. A と Bのみ買う

  cost[0] = a * x + b * y;
  
  // 2. C を出きるだけ買って、残りをA、Bで買う

  if(x >= y){
	cost[1] = 2 * c * y + a * (x - y);
  }
  else{
	cost[1] = 2 * c * x + b * (y - x);
  }

  // 3. Cのみ買う

  if(x >= y){
	cost[2] = 2 * c * x; 
  }
  else{
	cost[2] = 2 * c * y;
  }

  //min = *std::min_element(cost.begin(),cost.end());
  for(int ii = 0; ii < cost.size() ;ii++){
	if(cost[ii] < min){
	  min = cost[ii];
	}
  }
  //cost = an * a + bm * b + cl * c;
  cout << min << endl;
  return 0;
}

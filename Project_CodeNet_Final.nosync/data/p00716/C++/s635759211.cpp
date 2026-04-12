#include <iostream>
using namespace std;

main(){
  int m;
  while(cin >> m){
    for(int k=0;k<m;k++){
      int funds, period, n, ans=-1;
      cin >> funds >> period >> n;
      for(int i=0;i<n;i++){
	bool interest;
	double rate;
	int charge, tmp;
	cin >> tmp >> rate >> charge;
	if(tmp==1) interest=true;
	else interest=false;
	tmp=funds;
	
	if(interest){
	  for(int j=0;j<period;j++){
	    tmp+=(int)((double)tmp*rate)-charge;
	  }
	}
	else{
	  int sum=0;
	  for(int j=0;j<period;j++){
	    sum+=(int)((double)tmp*rate);
	    tmp-=charge;
	  }
	  tmp+=sum;
	}
	
	ans=max(ans, tmp);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
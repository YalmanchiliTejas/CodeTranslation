#include<iostream>
using namespace std;

int main(){
  int m,n;
  int s,y;

  cin >> m;
  while(m--){
    cin >> s >> y >> n;
    
    int ans = s;
    for(int i=0;i<n;i++){
      int sisan=s, rishi=0;
      int type, tesu;
      double ratio;

      cin >> type >> ratio >> tesu;

      for(int i=0;i<y;i++){
	int gain = (int)((double)sisan * ratio);
	if(type == 0)rishi += gain;
	else sisan += gain;
	sisan -= tesu;
      }

      ans = max(ans, sisan + rishi);
    }
    cout << ans << endl;
  }
}
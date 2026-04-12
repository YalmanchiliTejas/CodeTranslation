#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int m,s,y,n,k,d;
  double r;

  cin >> m;
  for(int i=0;i<m;i++){
    cin >> s >> y >> n;
    int ans = 0;
    for(int j=0;j<n;j++){
      cin >> k >> r >> d;
      int tmp = s;
      if(k==0){
	int tmp2 = 0;
	for(int x=0;x<y;x++){
	  tmp2 += (int)(tmp*r);
	  tmp -= d;
	}
	tmp += tmp2;
      }else{
	for(int x=0;x<y;x++){
	  tmp += (int)(tmp*r) - d;
	}
      }
      ans = max(ans,tmp);
    }
    cout << ans << endl;
  }
}
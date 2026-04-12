#include<iostream>
#include<vector>
using namespace std;
int main(){
  long long n,k;
  cin >> n >> k;
  vector<long long> cen(100);
  cen[0]=0;
  cen[1]=1;
  for(int i=2;i<=n+1;i++){
    cen[i] = cen[i-1]*2+1;
  }
  long long p=0;
  long long piv=k;
  for(int j=n+1;j>0;j--){
    if(piv<=cen[j]){
      if(piv==cen[j]){
	p += cen[j-1]+1;
	break;
      }
      else{
	if(piv==1){
	  break;
      }
	else{
	  piv -= 1;
	}
      }
    }
    else{
      if(piv==cen[j]*2-1){
	p += cen[j];
	break;
      }
      else{
	piv -= cen[j];
	p += cen[j-1]+1;
      }
    }
  }
  cout << p << "\n";
  
  return 0;
}

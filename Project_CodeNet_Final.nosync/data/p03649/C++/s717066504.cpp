#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long LL;

int main(){
  int N;
  cin >> N;
  vector<LL>a(N);
  for(int i=0;i<N;i++){
	cin >> a[i];
  }
  
  LL K=0;
  while(1){
	LL sum=0;
	for(int i=0;i<N;i++){
	  sum+=a[i]/N;
	  K+=a[i]/N;
	}
	for(int i=0;i<N;i++){
	  a[i]=sum-a[i]/N+a[i]%N;
	}
	for(int i=0;i<N;i++){
	  if(a[i]>=N){
		break;
	  }else if(i==N-1){
		cout << K << endl;
		return 0;
	  }
	}
	
  }
  return 0;
}
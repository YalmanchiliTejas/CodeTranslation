#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  let's try computer shogi!!!
 */

/*
  解説を書く余裕が無くなってきた
 */

int main(){
  int N;
  vector<long long int> A;
  cin >> N;
  A.resize(N);
  for(int i=0;i<N;++i){
    cin >>A[i]; 
  }

  long long int total = 0;
  while(1){
    bool stop = true;
    for(int i=0;i<N;++i){
      if(A[i] >= N){
	total += A[i]/N;
	for(int j=0;j<N;++j){
	  if(j!=i){
	    A[j] += A[i]/N;
	  }
	}
	A[i] = A[i]%N;
	stop = false;
	/*
	for(int k=0;k<N;++k){
	  cout<<A[k]<<" ";
	}
	cout<<endl;
	*/
      }
    }
    if(stop){
      break;
    }
  }
  cout<<total<<endl;
}
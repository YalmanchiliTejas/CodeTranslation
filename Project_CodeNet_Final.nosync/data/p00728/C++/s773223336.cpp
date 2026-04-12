#include <iostream>
using namespace std;
int N, A[1024],Max,Min,Sum;

int main(){
 while(cin >> N && N>0){
 Max=0;
 Min=1000;
  for (int i=0; i<N; ++i)
    cin >> A[i];
  for (int j=0; j<N; ++j){
	if(A[j]>Max) Max=A[j];
    }
  for (int k=0; k<N; ++k){
	if(A[k]<Min) Min=A[k];
	}
  for (int l=0; l<N; ++l){
    Sum += A[l];
	}
  cout<< (Sum-Max-Min)/(N-2) << endl;
  Sum=0;
 }
}	
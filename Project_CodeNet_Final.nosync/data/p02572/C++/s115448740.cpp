#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int>A(N);
  	int mod=1000000007;
  	long long sum=0;
  	long long answer=0;
  	for(int i=0;i<N;i++){
      cin>>A[i];
      sum+=A[i];
      sum%=mod;
    }
  	for(int j=0;j<N;j++){
      sum-=A[j];
      if(sum<0) sum+=mod;
      answer+=A[j]*sum;
      answer%=mod;
    }
  	cout<<answer<<endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  long long N;
  cin >> N;
  vector<int> A(N);
  for (int i=0;i<N;i++) cin >> A[i];
  sort(A.begin(),A.end());
  long long ans=0;
  for(int i=0;i<N/2;i++){
    ans+=(*(A.end()-i-1)-*(A.begin()+i))*2;
  }
  if( (N%2==0) ){
    ans+=*(A.begin()+N/2-1)-*(A.begin()+N/2);
  }else{
    if(
      *(A.begin()+N/2-1)-*(A.begin()+N/2)>
      *(A.begin()+N/2)-*(A.begin()+N/2+1) ){
      ans+=*(A.begin()+N/2-1)-*(A.begin()+N/2);
    }else{
      ans+=*(A.begin()+N/2)-*(A.begin()+N/2+1);
    }
  }
  cout << ans << endl;
}
  
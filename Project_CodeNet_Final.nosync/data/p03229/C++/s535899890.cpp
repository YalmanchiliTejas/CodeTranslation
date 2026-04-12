#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i=0;i<N;i++)  cin >> A.at(i);

  sort(A.begin(),A.end());
  long long ans=0;
  if(N%2==0){
    for(int i=0;i<N;i++){
      if(i<N/2) ans-=2*A.at(i);
      else  ans+=2*A.at(i);
    }
    ans+=A.at(N/2-1);
    ans-=A.at(N/2);
    cout << ans << endl;
    return 0;
  }

  long long tmp=0;
  for(int i=0;i<N;i++){
    if(i==N/2)  continue;
    if(i<N/2) tmp-=2*A.at(i);
    else  tmp+=2*A.at(i);
  }
  ans=max(tmp+(A.at(N/2-1)-A.at(N/2)),tmp+(A.at(N/2)-A.at(N/2+1)));
  cout << ans << endl;

  return 0;
}
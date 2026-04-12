#include<iostream>
using namespace std;
int N, S;
int main(){
  while(cin >> N && N>0){
    int sum = 0;
    int min = 1001;
    int max = -1;
    for(int i=0;i<N;++i){
      cin >> S;
      sum += S;
      if(min>S) min = S;
      if(max<S) max = S;
    }
    int ans = (sum-max-min)/(N-2);
    cout << ans << endl;
  }
}
      


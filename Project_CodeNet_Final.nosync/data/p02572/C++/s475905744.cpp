#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;  cin >> N;
  vector<long long>A(N);
  long long sum = 0;

  for(int i=0;i<N;i++){
    cin >> A.at(i);
    A.at(i) = A.at(i) % 1000000007;
    sum += A.at(i);
    sum = sum % 1000000007;
  }
  long long ans = 0;
  for(int i=0;i<N;i++){
    sum -= A.at(i);
    if(sum < 0) sum += 1000000007;
    ans += A.at(i)*sum;
    ans = ans % 1000000007;
  }
  cout << ans << endl;
}

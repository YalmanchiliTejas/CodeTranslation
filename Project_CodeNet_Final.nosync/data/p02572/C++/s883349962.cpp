#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;  cin >> N;
  vector<long long>A(N);
  long long X = 0;

  for(int i=0;i<N;i++){
    cin >> A.at(i);
    A.at(i) = A.at(i) % 1000000007;
    X += A.at(i);
    X = X % 1000000007;
  }
  long long sum = 0;
  for(int i=0;i<N;i++){
    X -= A.at(i);
    if(X < 0) X += 1000000007;
    sum += A.at(i)*X;
    sum = sum % 1000000007;
  }
  cout << sum << endl;
}

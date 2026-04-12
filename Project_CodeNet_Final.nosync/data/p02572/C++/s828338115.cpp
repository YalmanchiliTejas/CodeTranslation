#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int S;
  cin >> S;
  vector<long long> a(S);
  long long sum=0;
  for(int i=0;i<S;i++){
	cin >>a[i];
	sum += a[i];
  }
  int i;
  long long total=0;
  long long M = 1000000007;
  
  for(i=0;i<S-1;i++){
    sum -= a[i];
    total += (sum%M*a[i])%M;
    total %= M;
  }
  cout << total << endl;
}


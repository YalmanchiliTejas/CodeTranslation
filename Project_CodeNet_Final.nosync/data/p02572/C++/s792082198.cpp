#include <bits/stdc++.h>
using namespace std;

int main() {
  int m = 1000000007;
  int n;
  cin >> n;
  
  vector<int> v(n);
  long long sumN=0;
  for(int i=0; i<n; i++){
    cin >> v.at(i);
    sumN += v.at(i);
  }
  
  long long sum=0;
  for(int i=0; i<n-1; i++){
	sum += (sumN-v.at(i)) % m * (long long)v.at(i) % m;
    sumN -= (long long)v.at(i);
  }
  
  cout << sum % m << endl;
  
  
  
  
}

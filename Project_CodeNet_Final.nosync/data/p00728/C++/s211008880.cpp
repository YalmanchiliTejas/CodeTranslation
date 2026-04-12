#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  int n;
  while(true){
    cin >> n;
    if(n == 0) break;
    int sum = 0,average = 0;
    vector<long long> x(n);
    rep(i,n) cin >> x.at(i);
    sort(x.begin(),x.end());
    for(int i = 1; i < n-1; i++){
      sum +=x.at(i);
    }
    average = sum /(n-2);
    cout << average << endl;
  }
}

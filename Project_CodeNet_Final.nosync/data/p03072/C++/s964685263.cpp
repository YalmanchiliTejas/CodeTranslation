#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <string>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
const int MOD = 998244353;

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main()
{
  int N,count=0,num,max=0;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num;
    if(num >= max){
      max = num;
      count++;
    }
  }
  cout << count;
}

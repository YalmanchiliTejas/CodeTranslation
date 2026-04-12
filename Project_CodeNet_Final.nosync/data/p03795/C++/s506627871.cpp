#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;
  int x = 800*N;
  int y = 200 * (N/15);
  cout << x-y << endl;
  return 0;
}

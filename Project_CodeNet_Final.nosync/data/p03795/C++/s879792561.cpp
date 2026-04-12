#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   int n;
   cin >> n;
   cout << 800 * n - (n / 15) * 200 << endl;
   return 0;
}

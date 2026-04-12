#include <iostream>

#include <vector>

using namespace std;

int main()

{

  ios::sync_with_stdio(false);

  cin.tie(0);

  cout.tie(0);

  int n;

  cin >> n;

  long long sum = 0;

  vector<long long> a(n, 0), b(n, 0);

  for (int i = 0; i < n; i++)

    cin >> a[i];

    

  b[0] = a[n-1];

  b[0] %= 1000000007;

  

  for (int i = 1; i < n; i++)

  {

      b[i] = b[i-1] + a[n-i-1];

      b[i] %= 1000000007;

  }

  long long res = 0;

  for (int i = 0; i < n-1; i++)

  {

    res += (b[n-i-2] * a[i]);

    res %= 1000000007;

  }

  cout << res << endl;

  return 0;

}
#include <iostream>
#include <vector>
using namespace std;

void Input(vector<long long> &, int);
long long SumProduct(vector<long long> &, int);

int main()
{
  long long sum; //積の合計
  
  /* 入力 */
  int n;
  cin >> n;
  vector<long long> a(n);
  Input(a, n);
  
  /* 積の合計を計算 */
  sum = SumProduct(a, n);
  
  //出力
  cout << sum << endl;
  
  return 0;
}

void Input(vector<long long> &a, int n)
{
  /* 数列A取得 */
  for(int i=0 ; i < n ; i++)
  {
    cin >> a[i];
  }
  
}

long long SumProduct(vector<long long> &a, int n)
{
  int i;
  vector<long long> s(n+1);
  long long sum = 0;
  long long temp;
  long long mod = 1000000007;
  
  /* 累積和の計算 */
  s[0]=0;
  for(i=0 ; i < n ; i++)
  {
    s[i+1] = (s[i] + a[i])%mod;
  }
  
  /* 積の合計を計算 */
  for(i=0 ; i < n-1 ; i++)
  {
    temp = (s[n] - s[i+1]) % mod;
    if(temp < 0) temp += mod;
    temp = (a[i] * temp) % mod;
    sum = (sum + temp) % mod;
  }
  
  return sum;
}
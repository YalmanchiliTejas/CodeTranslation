#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define INF 1e9
using ll = std::int64_t;

template <class T>bool chmax(T &a, const T &b);
template <class T>bool chmin(T &a, const T &b);
//最大公約数
std::int64_t gcd(std::int64_t a, std::int64_t b);
std::int64_t gcd_s(std::int64_t aa, std::int64_t bb);
//ラングレス圧縮
std::vector<std::pair<char, std::int64_t>> rle(std::string str);
//素数判定
bool is_prime(std::int64_t n);
// 約数の列挙
std::vector<std::int64_t> divisor(std::int64_t n);
// 素因数分解
std::map<std::int64_t,std::int64_t> prime_factor(std::int64_t n);

//10^9 + 7
#define yojo 1000000007
#define MAX_NUM 200001

void Main()
{
  int r, g, b;
  cin >> r >> g >> b;
  int num = r * 100 + g * 10 + b;
  if (num % 4 == 0)
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }

  return;
}

int main()
{
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}

template <class T> bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T> bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return true;
  }
  return false;
}

//最大公約数
std::int64_t gcd(std::int64_t a, std::int64_t b)
{
  // a >= b && b != 0
  std::int64_t c;
  do
  {
    c = a % b;
    a = b;
    b = c;
  } while (c);

  return a;
}

//最大公約数安全版
std::int64_t gcd_s(std::int64_t aa, std::int64_t bb)
{
  std::int64_t a = max(aa, bb);
  std::int64_t b = min(aa, bb);
  std::int64_t c;
  if (b == 0)
  {
    return -1;
  }
  do
  {
    c = a % b;
    a = b;
    b = c;
  } while (c);

  return a;
}

//ラングレス圧縮
std::vector<std::pair<char, std::int64_t>> rle(std::string str)
{
  std::vector<std::pair<char, std::int64_t>> data;
  char now = str[0];
  std::int64_t count = 0;
  for (std::int64_t i = 0; i < str.size() + 1; i++)
  {
    if (i == str.size())
    {
      data.push_back(make_pair(str[i - 1], count));
      break;
    }
    else if (now != str[i])
    {
      data.push_back(make_pair(now, count));
      now = str[i];
      count = 0;
    }
    count++;
  }

  return data;
}

//素数判定
bool is_prime(std::int64_t n)
{
  for (std::int64_t i = 0; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  
  return n != 1;
}

//約数の列挙
std::vector<std::int64_t> divisor(std::int64_t n)
{
  std::vector<std::int64_t> res;
  for (int i = 0; i < n; i++)
  {
    if(n % i == 0){
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

// 素因数分解
std::map<std::int64_t, std::int64_t> prime_factor(std::int64_t n)
{
  std::map<std::int64_t, std::int64_t> res;
  for (int i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      ++res[i];
      n /= i;
    }
  }

  if (n != 1)
  {
    res[n] = 1;
  }
  
  return res;
}
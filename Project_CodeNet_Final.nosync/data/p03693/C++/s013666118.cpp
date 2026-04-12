#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define LLI(n) lli n; scanf("%lld", &n);
#define Sort(n) sort(n.begin(), n.end());
#define Reve(n) reverse(n.begin(), n.end());
#define YES puts("YES");
#define NO puts("NO");

//素数
bool IsPrime(lli num)
{
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false;
  long double sqrtNum = sqrt(num);
  for (lli i = 3; i <= sqrtNum; i += 2)
  {
    if (num % i == 0)return false;
  }
  return true;
}
//各桁の和
lli Sum(lli n)
{
  lli sum=0;
  if (n<0) return 0;
  while (n>0)
  {
    sum += n%10;
    n /= 10;
  }
  return sum;
}

int main(void)
{
  LLI(a);
  LLI(b);
  LLI(c);
  a = a*100 + b*10 + c;
  if(a%4==0)YES
  else NO
  return 0;
 }

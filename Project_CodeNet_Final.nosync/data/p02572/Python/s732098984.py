import sys
from sys import stdin
input = stdin.readline

mod = 10**9 + 7
class mint:
  def __init__(self, x):
    self.x = x % mod
  def __str__(self): return str(self.x)
  __repr__ = __str__
  def __add__(self, other):
    return(
      mint(self.x + other.x) if isinstance(other, mint) else
      mint(self.x + other)
    )
  def __sub__(self, other):
    return(
      mint(self.x - other.x) if isinstance(other, mint) else
      mint(self.x - other)
    )
  def __mul__(self, other):
    return(
      mint(self.x * other.x) if isinstance(other, mint) else
      mint(self.x * other)
    )
  def __truediv__(self,  other):
    return (
      mint(
        self.x * pow(other.x, mod - 2, mod)
      ) if isinstance(other, mint) else
      mint(self.x * pow(other, mod - 2, mod))
    )
  def __pow__(self, other):
    return (
      mint(pow(self.x, other.x, mod)) if isinstance(other, mint) else
      mint(pow(self.x, other, mod))
    )
  __radd__ = __add__
  def __rsub__(self, other):
    return(
      mint(other.x - self.x) if isinstance(other, mint) else
      mint(other - self.x)
    )
  __rmul__ = __mul__
  def __rtruediv__(self, other):
    return (
      mint(
        other.x * pow(self.x, mod - 2, mod)
      )if isinstance(other, mint) else
      mint(other * pow(self.x, mod - 2, mod))
    )
  def __rpow__(self, other):
    return (
      mint(pow(other.x, self.x, mod)) if isinstance(other, mint) else
      mint(pow(other, self.x, mod))
    )

n = int(input())
a = list(map(int, input().split()))
sum = [0] * n
sum[0] = a[0]
for i in range(n): 
  if (i==0): continue
  sum[i] += a[i] + sum[i-1]
ans = 0
for i in range(n-1):
  ans += mint(a[i] * (sum[n-1] - sum[i]))
print(ans)
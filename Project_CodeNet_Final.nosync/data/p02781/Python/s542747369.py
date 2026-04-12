n = int(input())
k = int(input())
import math

def nine(x, y):
  if y == 0:
    return 1
  elif x < y:
    return 0
  elif x == y:
    return 9 ** x
  elif y < 0:
    return 0
  else:
    r = 1
    for i in range(y):
      r *= x - i
      r //= i + 1
    r *= 9 ** y
    return r

ans = 0
if n > 10000:
  while n >= 10**(k-1):
    d = math.floor(math.log(n, 10))
    ans += nine(d, k)
    ans += nine(d, k-1) * (n//(10**d) - 1)
    n %= 10**d
    if k > 0:
      k -= 1
    else:
      break
  print(ans)
else:
  for i in range(1,n+1):
    if str(i).count('0')==len(str(i))-k:
      ans += 1
  print(ans)
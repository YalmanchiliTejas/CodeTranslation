n,x,m = list(map(int,input().split()))
import sys

a = [x]
while True:
  res = (a[-1]**2) % m
  if len(a) == n:
    print(sum(a))
    sys.exit()
  elif res == 0:
    print(sum(a))
    sys.exit()
  elif res in a:
    ai = a.index(res)
    aa = a[ai:]
    break
  else:
    a.append(res)

if len(a) >= n:
  print(sum(a[:n]) )
  sys.exit()

shuuki = len(aa)
shuuki_sum = sum(aa)

ans = sum(a) + shuuki_sum * ( (n-len(a)) // shuuki ) + sum( aa[:(n-len(a)) % shuuki] )
print(ans)

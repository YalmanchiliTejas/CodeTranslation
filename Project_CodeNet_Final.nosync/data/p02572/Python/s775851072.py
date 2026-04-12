import numpy as np

N = int(input())
A = np.array([int(i) for i in input().split()])
sum = 0

#累積和、二乗和の両方で1項ずつ求めてmodをとる
for x in A:
  sum += x
  sum %= (10**9+7)
#sum = A.sum() % (10**9+7)

sum2 = 0
for x in A:
  sum2 += x*x
  sum2 %= (10**9+7)
#sum2 = (A**2).sum() % (10**9+7)

ans = (sum**2 - sum2) % (10**9+7)
if ans < 0:
  ans += (10**9+7)
ans *= int((10**9+7+1)/2) 
ans %= (10**9+7)
print(int(ans))

from itertools import accumulate
MOD = 10**9+7
N = int(input())
A = list(map(int, input().split()))
Ac = list(accumulate(A))

ans = 0
for i in range(N):
  ans += A[i]*(Ac[-1]-Ac[i])
  ans = ans%MOD
print(ans)
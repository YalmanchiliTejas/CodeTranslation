from itertools import accumulate
N = int(input())
A = list(map(int,input().split()))
AA = list(accumulate(A))
MOD = 10**9+7
ans = 0

for i in range(N):
  ans += (A[i]*(AA[-1]-AA[i]))%MOD
print(ans%MOD)
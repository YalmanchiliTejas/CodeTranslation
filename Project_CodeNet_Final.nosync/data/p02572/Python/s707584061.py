mod = 10**9+7
N = int(input())
A = list(map(int,input().split()))
from itertools import accumulate
B = list(accumulate(A))
ans = 0
for i in range(N):
    ans += A[i]*(B[-1]-B[i])
    ans %= mod
print(ans)
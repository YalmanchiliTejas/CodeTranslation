import functools
import operator

N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7
ans = 0
v = sum(A)
for i in range(N-1):
    v -= A[i]
    ans += A[i]*v
print(ans%mod)

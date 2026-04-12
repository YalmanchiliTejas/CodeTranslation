import itertools

N = int(input())
A = list(int(x) for x in input().split())

mod = 10**9+7

sum_ = 0
ans = 0

for i in range(N):
    ans += sum_ * A[i]
    ans %= mod
    sum_ += A[i]
    sum_ %= mod

print(ans)

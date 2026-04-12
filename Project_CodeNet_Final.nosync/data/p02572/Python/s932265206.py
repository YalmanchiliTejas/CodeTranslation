from itertools import accumulate

N = int(input())
A = list(map(int,input().split()))

mod = 10 ** 9 + 7

ruiseki = list(accumulate(A))
ans = 0
for i in range(N-1):
    ans += A[i] * (ruiseki[-1] - ruiseki[i])
    ans %= mod

print(ans)
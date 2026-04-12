from itertools import accumulate
N = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7
Asum = list(accumulate(A))
X = Asum[-1]

ans = 0
for i, a in enumerate(A[:-1]):
    ans += a * (X - Asum[i])
    ans %= mod

print(ans)
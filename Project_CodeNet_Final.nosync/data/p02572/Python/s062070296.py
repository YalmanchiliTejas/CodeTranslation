import itertools
N = int(input())
A = [int(_) for _ in input().split()]
mod = 10**9 + 7
cum = [0] + list(itertools.accumulate(A))
ans = 0
for a, c in zip(A, cum):
    ans += a * c
    ans %= mod
print(ans)

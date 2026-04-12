import sys

N = int(input())
A = list(map(int, sys.stdin.readline().rsplit()))
mod = 10 ** 9 + 7
S = sum(A)

res = 0
for i in range(N):
    S -= A[i]
    res += (S % mod) * (A[i] % mod) % mod

print(res % mod)

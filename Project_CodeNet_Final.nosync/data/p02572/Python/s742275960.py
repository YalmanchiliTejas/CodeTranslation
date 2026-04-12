import sys

input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7
ans = 0
sum_a = sum(A)
for i in range(N):
    sum_a -= A[i]
    ans += A[i] * sum_a
    ans %= mod

print(ans)
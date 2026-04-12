import sys
input = sys.stdin.readline

# C - Sum of product of pairs
N = int(input())
A = list(map(int, input().split()))

sum_ = sum(A)
ans = 0

for i in range(N):
  sum_ -= A[i]
  ans += A[i] * sum_
  ans %= (10 ** 9 + 7)

print(ans)
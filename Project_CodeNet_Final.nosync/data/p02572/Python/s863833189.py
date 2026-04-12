import sys
input = sys.stdin.readline
 
N = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7

sum_A = sum(A)
ans = 0
for a in A[:-1]:
  sum_A -= a
  ans += a * sum_A

ans %= mod
print(ans)

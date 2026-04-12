import sys
readline = sys.stdin.readline

N = int(readline())
A = list(map(int,readline().split()))

DIV = 10 ** 9 + 7
ans = 0
cur = 0
for i in range(1, N):
  cur += A[i - 1]
  ans += A[i] * cur
  ans %= DIV
  
print(ans)
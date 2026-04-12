n = int(input())
A = list(map(int, input().split( )))
mod = 10**9 + 7
s = 0
ans = 0
for i in range(n-1):
  s = (A[i] + s)%mod
  ans = (ans + s*A[i+1])%mod

print(ans)
  
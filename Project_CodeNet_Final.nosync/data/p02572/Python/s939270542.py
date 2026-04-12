N=int(input())
A=list(map(int,input().split(' ')))

mod = 10**9+7
ans = 0
cs = 0
for i in range(N-1, -1, -1):
  ans = (ans+A[i]*cs) % mod
  cs = (cs+A[i]) % mod

print(ans)

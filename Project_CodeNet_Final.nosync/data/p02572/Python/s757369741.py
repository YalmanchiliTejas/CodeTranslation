n = int(input())
L = list(map(int,input().split()))
mod = 1000000007
ans = 0
x = 0
for i in range(n):
  ans = (ans + L[i]*x)%mod
  x = (x + L[i]%mod)
print(ans)
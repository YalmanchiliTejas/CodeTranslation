N = int(input())
As = list(map(int,input().split()))
MOD = 7+10**9
ans = 0
Asum = sum(As)
for i in range(N-1):
  Asum -= As[i]
  ans = (ans+As[i]*Asum)%MOD
print(ans)
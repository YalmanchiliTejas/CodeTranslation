N = int(input())
a_s = input().split(" ")
a_s = list(map(int, a_s))
asum = sum(a_s)

mod = 10**9 +7
ans = 0
for i in range(len(a_s)-1):
  asum -= a_s[i]
  ans += (asum*a_s[i])%mod
  if ans > mod:
    ans = ans%mod
      
print(ans)
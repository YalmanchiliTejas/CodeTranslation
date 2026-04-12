n = int(input())
a = list(map(int, input().split()))
s = [0]
ans = 0
mod = 10 ** 9 + 7
for i in range(n):
  s.append(s[i]+a[i])

s.pop(0)

for x in range(0, n-1):
  ans = ans +(a[x]*(s[n-1]-s[x]))
  
print(ans%mod)
        

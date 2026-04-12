n = int(input())
a = list(map(int,input().split()))
mod = 10**9 + 7

s = sum(a)
ans = 0

for i in a:
  s -= i
  s %= mod
  ans += s*i
  ans %= mod
  
print(ans)
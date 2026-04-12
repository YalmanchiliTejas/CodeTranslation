n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
total = sum(a)
total = total ** 2
cnt = 0
for i in range(n):
  cnt += a[i]**2

ans = (total - cnt) // 2
ans %= mod

print(ans)
  

mod = 10**9 + 7
n = int(input())
a = list(map(int, input().split()))
s = sum(a) % mod
a2 = [a[i]**2 % mod for i in range(n)]
s2 = sum(a2) % mod
ans2 = (s**2 - s2) % mod
if ans2 % 2 == 0:
  print(ans2 // 2)
else:
  print((ans2 + mod) // 2)

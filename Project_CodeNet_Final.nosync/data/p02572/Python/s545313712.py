n = input()
a = list(map(int, input().split()))

sa = sum(a)
ans = 0
p = 10**9 + 7
for i in a:
  sa -= i
  t = (i * sa) % p
  ans += t
  ans %= p

print(ans)
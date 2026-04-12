from functools import reduce
n = int(input())
S = [input() for _ in range(n)]
ans = ""
for i in range(26):
  now = chr(ord("a")+i)
  t = float("inf")
  for j in S:
    t = min(t, j.count(now))
  ans += now*t
print(ans)
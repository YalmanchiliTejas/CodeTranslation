from collections import Counter
n = int(input())
s = [None] * n
for i in range(n):
  s[i] = Counter(input())
ans = ""
for c in "abcdefghijklmnopqrstuvwxyz":
  cc = 50
  for si in s:
    cc = min(si.get(c, 0), cc)
  ans += c * cc
print(ans)
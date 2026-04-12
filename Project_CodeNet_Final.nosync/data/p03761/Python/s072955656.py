n = int(input())
s = [sorted(input()) for _ in range(n)]

words = list(set(s[0]))
d = {}
for i in words:
  t = float('inf')
  for j in range(n):
    p = s[j].count(i)
    if p < t:
      d[i] = p
      t = p

ans = ""
for i in sorted(d.items(), key = lambda x: x[0]):
  ans += i[0]*i[1]
print(ans)
n = int(input())
s = sorted([list(input()) for _ in range(n)])

word = list(set(s[0]))
d = {}
for i in word:
  t = 1000000
  for j in s:
    p = j.count(i)
    if p < t: t = p
  d[i] = t

ans = ""
for i in sorted(d.items()):
  ans += i[0]*i[1]
print(ans)
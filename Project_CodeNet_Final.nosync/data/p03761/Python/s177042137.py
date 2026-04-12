from collections import Counter
N = int(input())
r = dict([(chr(i), 50) for i in range(ord("a"), ord("z") + 1)])

for i in range(N):
  c = Counter(list(input()))
  for k, v in r.items():
    r[k] = min(v, c.get(k, 0))

ans = ""
for i in range(ord("a"), ord("z") + 1):
  ans += chr(i) * r[chr(i)]
print(ans)
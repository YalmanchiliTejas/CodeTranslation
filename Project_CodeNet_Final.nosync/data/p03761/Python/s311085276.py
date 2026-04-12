from collections import Counter

n = int(input())
s = [x for x in input()]
c = Counter(s)
for _ in range(n-1):
   s = [x for x in input()]
   d = Counter(s)
   for k in c.keys():
      c[k] = min(c[k], d[k])

c = sorted(c.items(), key=lambda x:x[0])
ans = ''
for k, v in c:
   ans += v * k
print(ans)

n = int(input())
s0 = str(input())
from collections import Counter
dct = dict(Counter(s0))
#print(dct)

for i in range(n - 1):
  s = str(input())
  d = Counter(s)
  for x in dct.items():
    if d.get(x[0]) != None:
      dct[x[0]] = min(x[1], d[x[0]])
    else:
      dct[x[0]] = 0

dct_sorted = sorted(dct.items(), key=lambda x: x[0])
#print(dct_sorted)

ans = ''
for x in dct_sorted:
  if x[1] > 0:
    ans += x[0] * x[1]
print(ans)
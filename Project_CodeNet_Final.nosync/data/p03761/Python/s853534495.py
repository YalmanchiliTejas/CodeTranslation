n = int(input())
s = [input() for _ in range(n)]
from collections import defaultdict
d = defaultdict(int)
for ele in "abcdefghijklmnopqrstuvwxyz":
  d[ele] = 0

for i, ele in enumerate(s):
  t = defaultdict(int)
  for l in ele:
    t[l] += 1
  if i==0:
    for k in d.keys():
      d[k] = t[k]
  for k in d.keys():
    d[k] = min(d[k], t[k])
  
ans = ""
for k, v in sorted(d.items(), key=lambda x:x[0]):
  if v>0:
    ans+=k*v
print(ans)
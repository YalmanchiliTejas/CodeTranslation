import string
import collections

n = int(input())
s = []
for i in range(n):
  s.append(input())

d = {}
for a in string.ascii_lowercase:
  d[a] = 100
#print(d)

for si in s:
  c = collections.Counter(si)
  # print(c)
  for a in string.ascii_lowercase:
    if a in d:
      d[a] = min(c[a],d[a])
    else:
      d[a] = 0
ans = []
for dk,dv in d.items():
  for i in range(dv):
    ans.append(dk)
print(''.join(ans))
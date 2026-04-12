import string
n = int(input())
m = set(list(string.ascii_lowercase))
l = []
for _ in range(n):
  s = input()
  m &= set(list(s))
  l.append(s)
r = ""
for s in m:
  r += s * min(l, key=lambda x: x.count(s)).count(s)
print(''.join(sorted(r)))

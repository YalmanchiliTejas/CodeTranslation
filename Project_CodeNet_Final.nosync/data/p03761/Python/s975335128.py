n = int(input())
Ss = []
cs = set("abcdefghijklmnopqrstuvwxyz")
ds = []
for i in range(n):
  S = input()
  d = {}
  for c in cs:
    d[c] = 0
  for c in S:
    d[c] += 1
  ds.append(d)
#print(ds)
md = {}
for c in cs:
  md[c] = min(map(lambda d: d[c], ds))
#print(md)
r = ""
for c in sorted(cs):
  r += c*md[c]
print(r)

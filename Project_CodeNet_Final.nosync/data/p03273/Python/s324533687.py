H, W = map(int, input().split())
a = [list(input()) for i in range(H)]
memo = []
b = []
for i in range(H):
  if "#" in a[i]:
    memo.append(i)
for x in memo:
  b.append(a[x])
memo = []
d = []
for c in zip(*b):
  d.append(c)
for i in range(W):
  if "#" in d[i]:
    memo.append(i)
e = []
for x in memo:
  e.append(d[x])
for r in zip(*e):
  print("".join(r))
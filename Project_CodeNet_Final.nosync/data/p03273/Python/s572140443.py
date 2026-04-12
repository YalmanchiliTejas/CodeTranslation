import sys
input = sys.stdin.readline
H, W = map(int, input().split())
a = [list(input())[: -1] for _ in range(H)]
b = []
c = set()
#print(a)
for i in range(H):
  f = 1
  for j in range(W):
    if a[i][j] == ".":
      f = 0
    else:
      f = 1
      break
  if f: b.append(a[i])
#print(b)
for j in range(W):
  f = 0
  for i in range(len(b)):
    if b[i][j] == ".":
      f = 1
    else:
      f = 0
      break
  if f: c.add(j)
#print(c)
for i in range(len(b)):
  res = ""
  for j in range(W):
    if j in c:
      continue
    res += b[i][j]
  print(res)
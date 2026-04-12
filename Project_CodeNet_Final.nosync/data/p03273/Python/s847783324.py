H, W = map(int, input().split())
a = [list(input()) for i in range(H)]

a1 = []
for h in range(H):
  if not all(s=="." for s in a[h]):
    a1.append(a[h])

a2 = [[] for i in range(len(a1))]
for w in range(W):
  tmp_a = [row[w] for row in a1]
  if not all(s=="." for s in tmp_a):
    for i in range(len(tmp_a)):
      a2[i].append(tmp_a[i])

for row in a2:
  print("".join(row))
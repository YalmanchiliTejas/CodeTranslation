H, W = map(int, input().split())
a = [input() for i in range(H)]
res = [0 for i in range(W)]
for i in range(W):
  for j in range(H):
    if a[j][i] != ".":
      break
    res[i] += 1
for i in range(H):
  if a[i][0:].count("#") >0:
    for j in range(W):
      if res[j] != H:
        print(a[i][j],end="")
    print("")
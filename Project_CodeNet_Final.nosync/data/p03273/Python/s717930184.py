H, W = map(int, input().split())
a = [input() for _ in range(H)]
for i in range(H):
  if a[i] != "." * W:
    s = ""
    for j in range(W):
      if [X[j] for X in a].count("#")>0:
        s += a[i][j]
    print(s)
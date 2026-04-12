H,W = map(int, input().split())
A = [input() for h in range(H)]
row = H*[False]
col = W*[False]

for h in range(H):
  for w in range(W):
    if A[h][w]=="#":
      row[h] = True
      col[w] = True

for h in range(H):
  if row[h]:
    for w in range(W):
      if col[w]:
        print(A[h][w],end="")
    print()
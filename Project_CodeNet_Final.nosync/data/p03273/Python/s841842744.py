H, W = list(map(lambda x: int(x), input().split(" ")))
A = []
ans = []
whiterows = []
whitecols = []

for i in range(H):
  A.append(list(input()))
  if A[i].count("#") == 0:
    whiterows.append(i)

tA = [list(a) for a in zip(*A)]
for j in range(W):
  if tA[j].count("#") == 0:
    whitecols.append(j)

rows = list(filter(lambda r: r not in whiterows, list(range(H))))
cols = list(filter(lambda c: c not in whitecols, list(range(W))))

for k in rows:
  ans.append("".join([A[k][l] for l in cols]))

print("\n".join(ans))
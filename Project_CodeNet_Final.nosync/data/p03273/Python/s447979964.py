H, W = map(int, input().split())
X = []
res = []
F = [True] * W

for i in range(H):
  x = list(input())
   
  if x.count("#") != 0:
    X.append(x)

  for j in range(W):
    if x[j] == "#":
      F[j] = False

for k in range(len(X)):
  r = ""
  for l in range(W):
    if not F[l]:
      r += (X[k][l])
  print(r)
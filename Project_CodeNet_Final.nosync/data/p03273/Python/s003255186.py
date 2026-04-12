H, W = map(int,input().split())
a = []
for i in range(H):
  a1 = input()
  if "#" in a1:
    a.append(a1)

b = []
for i in range(W):
  for j in range(len(a)):
    if a[j][i] == "#":
      break
  else:
      b.append(i)

for i in range(len(a)):
  ans = ""
  for j in range(W):
    if not j in b:
      ans += a[i][j]
  print(ans)
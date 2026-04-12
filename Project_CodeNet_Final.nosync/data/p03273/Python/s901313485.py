H,W = map(int,input().split())
m = []
for i in range(H):
  m.append(input())

ly = []
lt = []
for i in range(H):
  if "#" in m[i]:
    ly.append(i)
for j in range(W):
  c = 0
  for k in range(H):
    if m[k][j] == "#":
      c += 1
      break
  if c == 1:
    lt.append(j)    
###
for i in ly:
  s =""
  for j in lt:
    s += m[i][j]
  print(s)
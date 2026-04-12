h,w = map(int,input().split())
mat = []
for i in range(h):
  g = list(input())
  if g.count(".") != w:
    mat.append(g)


for i in range(w-1, -1, -1):
  count = 0
  for j in range(len(mat)):
    if mat[j][i] == ".":
      count += 1
  if count == len(mat):
    for j in range(len(mat)):
      mat[j].pop(i)

for h in range(len(mat)):
  print("".join(mat[h]))
    

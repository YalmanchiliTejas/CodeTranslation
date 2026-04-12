H,W = map(int,input().split())
mat = [input() for _ in range(H)]
#print(mat)

#[mat.remove(row) for row in mat[::] if ("#" not in row)]
#print(mat)

for row in mat[::]:
  if "#" not in row:
    mat.remove(row)
#print(mat)

showCol = [i for i in range(W) if "#" in [row[i] for row in mat]]
#print(showCol)

showCol = []
#for i in range(W):
#  if "#" in [row[i] for row in mat]:
#    showCol.append(i)
for i in range(W):
  for row in mat:
    if "#" in row[i]:
      showCol.append(i)
setCol = set(showCol)
#print(setCol)

print("\n".join(["".join([row[c] for c in setCol]) for row in mat]))

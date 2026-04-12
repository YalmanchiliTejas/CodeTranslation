def rotate(mat):
  mat2 = []
  for i in range(len(mat[0])):
    s = ""
    for k in range(len(mat)):
      s = s + mat[k][i]
    mat2.append(s)
  return mat2

H,W=map(int, input().split())
mat = []
for i in range(H):
  a = input()
  if "#" in a:
    mat.append(a)

for count in range(H+W):
  for i in range(len(mat)-1, -1, -1):
    if not "#" in mat[i]:
      del mat[i]
  mat = rotate(mat)
  for i in range(len(mat)-1, -1, -1):
    if not "#" in mat[i]:
      del mat[i]
  mat = rotate(mat)
  
for i in range(len(mat)):
  print(mat[i])

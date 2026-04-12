H,W = map(int,input().split())
A = [list(input()) for _ in range(H)]

emp_row = [False] * H
emp_col = [False] * W

for i in range(H):
  isEmp = True
  for j in range(W):
    if A[i][j] == "#":
      isEmp = False
      break
  emp_row[i] = isEmp
  
for i in range(W):
  isEmp = True
  for j in range(H):
    if A[j][i] == "#":
      isEmp = False
  emp_col[i] = isEmp
  
ANS = []
for i in range(H):
  if emp_row[i]:
    continue
  row = []
  for j in range(W):
    if emp_col[j]:
      continue
    row.append(A[i][j])
  ANS.append(row)
  
for a in ANS:
  print("".join(a))
    
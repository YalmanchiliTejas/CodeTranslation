H,W=map(int,input().split())

mat=[]
for i in range(H):
  array=[x=="." for x in input()]
  mat.append(array)
#print(mat)

allW_row=[]
for i in range(H):
  allW_line=True
  for j in range(W):
    if not mat[i][j]:
      allW_line=False
      break
  allW_row.append(allW_line)
  
allW_col=[]
for j in range(W):
  allW_line=True
  for i in range(H):
    if not mat[i][j]:
      allW_line=False
      break
  allW_col.append(allW_line)
  
#print(allW_row)
#print(allW_col)
for i in range(H):
  if allW_row[i]:
    continue
    
  array_list=[]
  for j in range(W):
    if not allW_col[j]:
      if mat[i][j]:
        array_list.append(".")
      else:
        array_list.append("#")
  print("".join(array_list))
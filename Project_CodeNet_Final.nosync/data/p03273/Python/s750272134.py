H,W=map(int,input().split())
matrix=[list(map(str,input().split())) for i in range(H)]
count_delete_H=0
count_delete_W=0

for i in range(H):
  matrix[i-count_delete_H]=list(*matrix[i-count_delete_H])
  if(matrix[i-count_delete_H].count('#')==0):
    del matrix[i-count_delete_H]
    count_delete_H+=1
    
matrix_t = [list(x) for x in zip(*matrix)]
for i in range(W):
  if(matrix_t[i-count_delete_W].count('#')==0):
    del matrix_t[i-count_delete_W]
    count_delete_W+=1
    
matrix_tt = [list(x) for x in zip(*matrix_t)]
for i in range(H-count_delete_H):
  for j in range(W-count_delete_W):
    print(matrix_tt[i][j],end='')
  print('')
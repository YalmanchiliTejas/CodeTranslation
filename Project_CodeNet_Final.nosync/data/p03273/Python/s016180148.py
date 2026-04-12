H,W=map(int,input().split())
matrix=[list(map(str,input().split())) for i in range(H)]
count_delete_H=0 #消した数を記憶しておく
count_delete_W=0 #同上

for i in range(H):
  matrix[i-count_delete_H]=list(*matrix[i-count_delete_H])#要素の文字列を1文字ごとに分解
  #print(matrix[i-count_delete_H].count('#'))
  if(matrix[i-count_delete_H].count('#')==0):
    del matrix[i-count_delete_H]
    count_delete_H+=1
    
matrix_t = [list(x) for x in zip(*matrix)]#転置をとる。
for i in range(W):
  #print(matrix_t[i-count_delete_W].count('#'))
  if(matrix_t[i-count_delete_W].count('#')==0):
    del matrix_t[i-count_delete_W]
    count_delete_W+=1
    
matrix_tt = [list(x) for x in zip(*matrix_t)]#転置をとって元に戻す。
#print(matrix_tt)
for i in range(H-count_delete_H):
  for j in range(W-count_delete_W):
    print(matrix_tt[i][j],end='')
  print('')#改行
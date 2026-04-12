# coding:utf-8
import numpy as np

H, W = map(int, input().split())
cell = []
for i in range(H):
    cell.append(input())

mat = np.empty((H, W))
for i in range(H):
    for j in range(W):
        if cell[i][j] == '.':
            mat[i,j] = 0
        if cell[i][j] == '#':
            mat[i,j] = 1

col_del = np.all(mat == 0, axis=0)
row_del = np.all(mat == 0, axis=1)
col_index = np.where(col_del==True)
row_index = np.where(row_del==True)
#print(col_index)

res = np.delete(mat, row_index, axis=0)
res = np.delete(res, col_index, axis=1)
#print(res)
Hn = res.shape[0]
Wn = res.shape[1]

a =''
for i in range(Hn):
    ans = []
    for j in range(Wn):
        if res[i,j] == 0:
            ans.append('.')

        if res[i,j] == 1:
            ans.append('#')
    #print(ans)
    a += '\n' + ''.join(ans)

print(a)

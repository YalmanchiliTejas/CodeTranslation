import numpy as np
h,w = map(int,input().split())
lst = []
ans = []
for i in range(h):
    s = input()
    tmp = s.replace('.','')
    if tmp:
        lst.append(list(s))
matrix = np.array(lst)
matrix = matrix.T
for i in range(w):
    s = ''.join(matrix[i])
    tmp = s.replace('.','')
    if tmp:
        ans.append(list(s))
matrix2 = np.array(ans)
matrix2 = matrix2.T
for j in matrix2:
    s = ''.join(j)
    print(s)
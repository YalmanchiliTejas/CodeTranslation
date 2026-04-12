import numpy as np
h,w=map(int,input().split())
A= [list(input()) for i in range(h)]
A_np=np.array(A)
del_index=[]
del_row=[]
for i in range(h):
    if A[i].count('.')==len(A[i]):
        del_index.append(i)
for j in range(w):
    c=0
    for i in range(h):
        if A[i][j]=='#':
            c+=1
    if c==0:
        del_row.append(j)
del_index.sort(reverse=True)
del_row.sort(reverse=True)
for j in del_row:
    A_np=np.delete(A_np,j,1)
for i in del_index:
    A_np=np.delete(A_np,i,0)
ans=list(A_np)
if ans ==[]:
    print()
else:
    for i in range(len(ans)):
        print(*ans[i],sep='')
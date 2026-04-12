import numpy as np
h,w=map(int,input().split())
grid=np.empty((h,w),dtype="<U")
for i in range(h):
    s=list(input())
    grid[i]=s

del_row=[]
del_col=[]
for i in range(h):
    if all(grid[i]=="."):
        del_row.append(i)
for j in range(w):
    if all(grid[:,j]=="."):
        del_col.append(j)
        
grid=np.delete(grid, del_row, 0)
grid=np.delete(grid, del_col, 1)

for i in grid:
    print("".join(i))
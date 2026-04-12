
import numpy as np

H,W = map(int, input().split())

a = [list(str(input())) for i in range(H)]
b = []

for i in range(H):
    for j in range(W):
        if a[i][j]!=".":
            b.append(a[i])
            break

del_targets = []
b_arr = np.array(b)

#print(b_arr)
            
for j in range(W):
    #print(b_arr[:,j])
    if b_arr[:,j].tolist().count(".") == len(b_arr[:,j].tolist()):
        del_targets.append(j)
        
ans = np.delete(b_arr, del_targets, 1)

for i in range(len(ans)):
    print(str(''.join(ans[i,:])))
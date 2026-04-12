import numpy as np
h,w=map(int,input().split())
a=np.array([list(input()) for i in range(h)])
c=0
for j in range(h,0,-1):
    if all([k=='.' for k in a[j-1,:]]):
        a=np.delete(a,j-1,0)
        c+=1
for l in range(w,0,-1):
    if all([n=='.' for n in a[:,l-1]]):
        a=np.delete(a,l-1,1)
for m in range(h-c):
    print(''.join(a[m,:]))
import numpy as np
H,W = map(int,input().split())
a = np.array([list(input()) for _ in range(H)])
dlisx = np.any(a == "#",axis = 0)
dlisy = np.any(a == "#",axis = 1)
dlx = []
dly = []
for i,x in enumerate(dlisx):
    if not x:
        dlx.append(i)
for i,y in enumerate(dlisy):
    if not y:
        dly.append(i)

ans = np.delete(np.delete(a,dlx,1),dly,0)
for a in ans:
    print("".join(a))



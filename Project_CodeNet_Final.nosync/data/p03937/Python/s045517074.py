from queue import Queue
import numpy as np

H,W = map(int,input().split())

B = []
for i in range(H):
    B_sub = []
    for j in input():
        if j == "#":B_sub.append(5)
        else: B_sub.append(-1)
    B.append(B_sub)
    
qy,qx = Queue(),Queue()
qy.put(0)
qx.put(0)

isok = True
while(isok):
    if qy.empty() and qx.empty(): break
    else:
        y,x = qy.get(),qx.get()
        if y==0 and x==0: B[y][x] = 0

        if y<H-1 and B[y+1][x]==5:
            B[y+1][x] = 0
            qy.put(y+1)
            qx.put(x)
            if 5 in B[y]: isok = False
        elif x<W-1 and B[y][x+1]==5:
            B[y][x+1] = 0
            qy.put(y)
            qx.put(x+1)
            if 5 in np.array(B).T[x]: isok = False
            
            
if isok:
    print("Possible")
else:
    print("Impossible")
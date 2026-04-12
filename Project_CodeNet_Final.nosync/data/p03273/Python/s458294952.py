import numpy as np
 
H,W = map(int,input().split())
MAP = []
for _ in range(H):
    tmp = tuple(input())
    MAP.append(tmp)
 
MAP = np.array(MAP)
L = []
for i in range(H):
    if all(MAP[i,:] == '.'):
        L.append(i)
 
MAP = np.delete(MAP,L,0)
L = []
for i in range(W):
    if all(MAP[:,i] == '.'):
        L.append(i)
 
MAP = np.delete(MAP,L,1)
for m in MAP:
    print(''.join(m))

import numpy as np
H,W = (int(X) for X in input().split())
A = np.zeros((H,W),dtype=bool)
for TH in range(0,H):
    A[TH,:] = np.array([True if X=='.' else False for X in input()])
    Row = [TH for TH in range(0,H) if np.all(A[TH,:])==True]
for TW in range(0,W):
    Column = [TW for TW in range(0,W) if np.all(A[:,TW])==True]

A = np.delete(np.delete(A,Row,0),Column,1)
for THD in range(0,H-len(Row)):
    Disp = ['.' if X==True else '#' for X in A[THD,:]]
    print(''.join(Disp))
import numpy as np,sys
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
H,W = LI()
a = np.array([[s for s in S()] for _ in range(H)])
a = a[(a=='#').any(axis=1)]
a = a.T
a = a[(a=='#').any(axis=1)]
a = a.T.tolist()
for x in a:
    print(*x,sep='')

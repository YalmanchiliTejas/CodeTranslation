from collections import deque

d = deque()
N=int(input())
A=[]
for i in range(N):
    a=int(input())
    A.append(a)
A=sorted(A)
A2=A.copy()
#61823
#351914
#419153
B=deque()
#最初に大きい方
B.append(A.pop(-1))
while len(A)>0:
    if len(A)>0:
        B.appendleft(A.pop(0))
    if len(A)>0:
        B.append(A.pop(0))
    if len(A)>0:
        B.appendleft(A.pop(-1))
    if len(A)>0:
        B.append(A.pop(-1))
B=list(B)
C=deque()
#最初に小さい方
C.append(A2.pop(0))
while len(A2)>0:
    if len(A2)>0:
        C.appendleft(A2.pop(-1))
    if len(A2)>0:
        C.append(A2.pop(-1))
    if len(A2)>0:
        C.appendleft(A2.pop(0))
    if len(A2)>0:
        C.append(A2.pop(0))
C=list(C)
countb=0
countc=0
for i in range(1,N):
    countb+=abs(B[i]-B[i-1])
    countc+=abs(C[i]-C[i-1])
print(max(countb, countc))

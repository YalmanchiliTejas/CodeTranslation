import sys,math,collections,itertools
input = sys.stdin.readline

N=int(input())
A = sorted([int(input()) for _ in range(N)])
B = sorted(A[::1],reverse = 1)
qA = collections.deque(A)
qB = collections.deque(B)
Al = []
Bl = []
i = 1
while qA:
    if i:
        Al.append(qA.pop())
        Bl.append(qB.pop())
    else:
        Al.append(qA.popleft())
        Bl.append(qB.popleft())
    i = (i+1)%2
Al = [Al[-1]]+Al[:-1:]
Bl = [Bl[-1]]+Bl[:-1:]
cntA=0
cntB=0
for i in range(N-1):
    cntA += abs(Al[i+1]-Al[i])
    cntB += abs(Bl[i+1]-Bl[i])
print(max(cntA,cntB))

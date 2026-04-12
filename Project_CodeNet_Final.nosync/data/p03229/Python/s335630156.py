from collections import deque

N = int(input())
A = []
B = []

for i in range(N):

    a = int(input())

    A.append(a)

A.sort()

now = A.pop(0)
L = now
R = now
ans = 0
Lind = 0
Rind = -1

for i in range(N-1):

    if abs(L-A[Lind]) == max(abs(L-A[Lind]),abs(L-A[Rind]),abs(R-A[Lind]),abs(R-A[Rind])):
        ans += abs(L-A[Lind])
        L = A[Lind]
        Lind += 1

    elif abs(L-A[Rind]) == max(abs(L-A[Lind]),abs(L-A[Rind]),abs(R-A[Lind]),abs(R-A[Rind])): 
        ans += abs(L-A[Rind])
        L = A[Rind]
        Rind -= 1

    elif abs(R-A[Lind]) == max(abs(L-A[Lind]),abs(L-A[Rind]),abs(R-A[Lind]),abs(R-A[Rind])):
        ans += abs(R-A[Lind])
        R = A[Lind]
        Lind += 1

    elif abs(R-A[Rind]) == max(abs(L-A[Lind]),abs(L-A[Rind]),abs(R-A[Lind]),abs(R-A[Rind])):
        ans += abs(R-A[Rind])
        R = A[Rind]
        Rind -= 1

    else:
        print ("eeror")

    #print (A,L,R,ans)

print (ans)
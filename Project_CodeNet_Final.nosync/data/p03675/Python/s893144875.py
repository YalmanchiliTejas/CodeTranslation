from collections import deque
N=int(input())
A=[i for i in input().split()]
s=deque()
s.append(A[0])
if N%2==1:
    for i in range(1,N):
        if i%2==1:
            s.append(A[i])
        else:
            s.appendleft(A[i])
else:
    for i in range(1,N):
        if i%2==0:
            s.append(A[i])
        else:
            s.appendleft(A[i])
print(' '.join(map(str,s)))
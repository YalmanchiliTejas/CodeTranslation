#================================================
from collections import deque

N=int(input())
A=[0]*N
for i in range(N):
    A[i]=int(input())
A.sort()
#=====================
Q=deque(range(1,N))
R=deque([0])
for i in range((N-1)//2):
    if i%2:
        x=Q.popleft()
        y=Q.popleft()
    else:
        x=Q.pop()
        y=Q.pop()

    R.appendleft(x)
    R.append(y)

if Q:
    x=Q.pop()
    R.appendleft(x)

X=[0]*N
Y=[0]*N
for i in range(N):
    X[i]=A[R[i]]
    Y[i]=A[-(R[i]+1)]

alpha=0
beta=0

for i in range(N-1):
    alpha+=abs(X[i+1]-X[i])
    beta +=abs(Y[i+1]-Y[i])
print(max(alpha,beta))

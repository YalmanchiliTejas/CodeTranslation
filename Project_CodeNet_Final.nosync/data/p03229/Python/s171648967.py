from collections import deque

N = int(input())
A = []
for _ in range(N):
    A.append(int(input()))
    
A.sort()
D = deque()
for i in range(N):
    if i%4==0:
        D.append(A[i//2])
    elif i%4==1:
        D.appendleft(A[-1-(i-1)//2])
    elif i%4==2:
        D.appendleft(A[i//2])
    else:
        D.append(A[-1-(i-1)//2])
ans1 = 0
for i in range(N-1):
    ans1 += abs(D[i+1]-D[i])

A.sort(reverse=True)
D = deque()
for i in range(N):
    if i%4==0:
        D.append(A[i//2])
    elif i%4==1:
        D.appendleft(A[-1-(i-1)//2])
    elif i%4==2:
        D.appendleft(A[i//2])
    else:
        D.append(A[-1-(i-1)//2])
ans2 = 0
for i in range(N-1):
    ans2 += abs(D[i+1]-D[i])
    
print(max(ans1,ans2))
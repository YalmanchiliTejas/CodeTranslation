N=int(input())
A=[int(input())for _ in range(N)]

from collections import*
A.sort()
ans1=deque()
ans1.append(A[0])
i=j=1
while i<=N-j:
    if i<=N-j:
        ans1.append(A[-j])
        j+=1
    if i<=N-j:
        ans1.appendleft(A[-j])
        j+=1
    if i<=N-j:
        ans1.append(A[i])
        i+=1
    if i<=N-j:
        ans1.appendleft(A[i])
        i+=1
ans1=list(ans1)
ans1=sum(abs(x-y)for x,y in zip(ans1,ans1[1:]))

A=A[::-1]
ans2=deque()
ans2.append(A[0])
i=j=1
while i<=N-j:
    if i<=N-j:
        ans2.append(A[-j])
        j+=1
    if i<=N-j:
        ans2.appendleft(A[-j])
        j+=1
    if i<=N-j:
        ans2.append(A[i])
        i+=1
    if i<=N-j:
        ans2.appendleft(A[i])
        i+=1
ans2=list(ans2)
ans2=sum(abs(x-y)for x,y in zip(ans2,ans2[1:]))

print(max(ans1,ans2))
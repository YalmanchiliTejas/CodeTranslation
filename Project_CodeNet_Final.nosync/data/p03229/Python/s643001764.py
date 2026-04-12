import collections

N=int(input())

A=[int(input()) for i in range(N)]

A.sort()

ans=[A[0],A[-1]]
ans=collections.deque(ans)
l=1
r=-2
n=[0]*4
ansn=abs(A[0]-A[-1])
for i in range(N-2):
    n[0]=abs(A[l]-ans[0])
    n[1]=abs(A[l]-ans[-1])
    n[2]=abs(A[r]-ans[0])
    n[3]=abs(A[r]-ans[-1])
    if n[0]==max(n):
        ansn+=n[0]
        ans.appendleft(A[l])
        l+=1
    elif n[1]==max(n):
        ansn+=n[1]
        ans.append(A[l])
        l+=1
    elif n[2]==max(n):
        ansn+=n[2]
        ans.appendleft(A[r])
        r-=1
    elif n[3]==max(n):
        ansn+=n[3]
        ans.append(A[r])
        r-=1

print(ansn)
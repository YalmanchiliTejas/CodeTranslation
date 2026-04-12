from collections import deque
N=int(input())
A=list(map(int,input().strip().split(' ')))
q=deque([])
for i in range(len(A)):
    if i%2==0:
        q+=[A[i]]
    else:
        q.appendleft(A[i])
ans=0
if (len(A)-1)%2==1:
    ans=(list(q))
else:
    ans=(list(q)[::-1])
ans=[str(x) for x in ans]
print(" ".join(ans))
N=int(input())
A=[int(input()) for i in range(N)]
from collections import deque
A.sort()
q=deque(A)
q2=deque()
q2.append(q.popleft())
k=N-1
while(k>0):
  if len(q)>0:
    q2.appendleft(q.pop())
    k-=1
  if len(q)>0:
    q2.append(q.pop())
    k-=1
  if len(q)>0:
    q2.appendleft(q.popleft())
    k-=1
  if len(q)>0:
    q2.append(q.popleft())
    k-=1
  if len(q)==0:
    break
prev=q2.popleft()
ans=0
for i in range(N-1):
  now=q2.popleft()
  ans+=abs(now-prev)
  prev=now

q=deque(A)
q2=deque()
q2.append(q.pop())
k=N-1
while(k>0):
  if len(q)>0:
    q2.appendleft(q.popleft())
    k-=1
  if len(q)>0:
    q2.append(q.popleft())
    k-=1
  if len(q)>0:
    q2.append(q.pop())
    k-=1
  if len(q)>0:
    q2.appendleft(q.pop())
    k-=1
  if len(q)==0:
    break
prev=q2.popleft()
tmp=0
for i in range(N-1):
  now=q2.popleft()
  tmp+=abs(now-prev)
  prev=now  
  
print(max(ans,tmp))  
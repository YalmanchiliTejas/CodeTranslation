from collections import deque
n=int(input())
a=[int(input()) for i in range(n)]
a.sort()
q=deque()
for i in range(n//2):
  if i%2==0:
    q.appendleft(a[n-i-1])
    q.append(a[i])
  else:
    q.appendleft(a[i])
    q.append(a[n-i-1])
ans=0
q1=list(q)
if n%2==0:
  for i in range(n-1):
    ans+=abs(q1[i]-q1[i+1])
  print(ans)
else:
  for i in range(len(q1)-1):
    ans+=abs(q1[i]-q1[i+1])
  print(ans+max(abs(a[n//2]-q1[0]),abs(a[n//2]-q1[len(q1)-1])))
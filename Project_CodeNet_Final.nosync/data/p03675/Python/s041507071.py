from collections import deque
n=int(input())
a=list(map(int,input().split()))
q=deque()
for i in range(n):
  if i%2==0:
    q.append(a[i])
  else:
    q.appendleft(a[i])
if n%2==1:
  q.reverse()
print(*q)
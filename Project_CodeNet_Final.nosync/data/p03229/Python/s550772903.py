from collections import deque 
n = int(input())
d = deque()
l=[]
for i in range(n):
  a = int(input())
  l.append(a)
l.sort()
l = deque(l)
flag=0
flag1=0
q = l.popleft()
d.append(q)
while l:
  a =abs(d[0]-l[0])
  b = abs(d[0]-l[-1])
  c = abs(d[-1]-l[-1])
  d1 = abs(d[-1]-l[0])
  m = max(a,b,c,d1)
  if a==m:
    f = l.popleft()
    d.appendleft(f)
  elif b==m:
    f = l.pop()
    d.appendleft(f)
  elif c==m:
    f = l.pop()
    d.append(f)
  elif d1==m:
    f = l.popleft()
    d.append(f)
ans = 0
for i in range(n-1):
  ans+=abs(d[i+1]-d[i])
print(ans)
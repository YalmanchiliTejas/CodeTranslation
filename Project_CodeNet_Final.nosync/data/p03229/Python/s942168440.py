from collections import deque
n=int(input())
a=deque(sorted([int(input()) for _ in range(n)]))
b=deque([a.pop()])
i=0
while a:
  if max(abs(a[-1]-b[-1]),abs(a[-1]-b[0]),abs(a[0]-b[-1]),abs(a[0]-b[0]))==abs(a[-1]-b[-1]):
    b.append(a.pop())
  elif max(abs(a[-1]-b[-1]),abs(a[-1]-b[0]),abs(a[0]-b[-1]),abs(a[0]-b[0]))==abs(a[-1]-b[0]):
    b.appendleft(a.pop())
  elif max(abs(a[-1]-b[-1]),abs(a[-1]-b[0]),abs(a[0]-b[-1]),abs(a[0]-b[0]))==abs(a[0]-b[0]):
    b.appendleft(a.popleft())
  else:
    b.append(a.popleft())
ans=0
for i in range(n-1):
  ans+=abs(b[i]-b[i+1])
print(ans)
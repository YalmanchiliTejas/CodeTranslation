import collections

n=int(input())
arr=[int(input()) for _ in range(n)]
arr=sorted(arr)
if n%2==1:
  q=collections.deque()
  q.append(arr[0])
  l=1
  r=n-1
  move=1
  while 1:
    q.appendleft(arr[r])
    r-=1
    q.append(arr[r])
    r-=1
    move+=2
    if move==n:
      break
    q.appendleft(arr[l])
    l+=1
    q.append(arr[l])
    l+=1
    move+=2
    if move==n:
      break
  q=list(q)
  ans1=0
  for i in range(n-1):
    ans1+=abs(q[i+1]-q[i])
  q=collections.deque()
  q.append(arr[-1])
  l=0
  r=n-2
  move=1
  while 1:
    q.appendleft(arr[l])
    l+=1
    q.append(arr[l])
    l+=1
    move+=2
    if move==n:
      break
    q.appendleft(arr[r])
    r-=1
    q.append(arr[r])
    r-=1
    move+=2
    if move==n:
      break
  q=list(q)
  ans2=0
  for i in range(n-1):
    ans2+=abs(q[i+1]-q[i])
  ans=max(ans1,ans2)
  print(ans)
else:
  q=collections.deque()
  q.append(arr[0])
  l=1
  r=n-1
  move=1
  while 1:
    if n-move==1:
      break
    q.appendleft(arr[r])
    r-=1
    q.append(arr[r])
    r-=1
    move+=2
    if n-move==1:
      break
    q.appendleft(arr[l])
    l+=1
    q.append(arr[l])
    l+=1
    move+=2
  q=list(q)
  ans1=0
  for i in range(n-2):
    ans1+=abs(q[i+1]-q[i])
  ans1+=max(abs(arr[l]-q[0]),abs(arr[l]-q[-1]))
  q=collections.deque()
  q.append(arr[-1])
  l=0
  r=n-2
  move=1
  while 1:
    if n-move==1:
      break
    q.appendleft(arr[l])
    l+=1
    q.append(arr[l])
    l+=1
    move+=2
    if n-move==1:
      break
    q.appendleft(arr[r])
    r-=1
    q.append(arr[r])
    r-=1
    move+=2
  q=list(q)
  ans2=0
  for i in range(n-2):
    ans2+=abs(q[i+1]-q[i])
  ans2+=max(abs(arr[r]-q[0]),abs(arr[r]-q[-1]))
  ans=max(ans1,ans2)
  print(ans)
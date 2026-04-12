from collections import deque
n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
b = list(a)
a = deque(a)
b = deque(b)

l=a.popleft() 
r=l
count=0
ans=0
while len(a)>0:
  if count%4==0:
    temp=a.pop()
    ans+=abs(temp-l)
    l=temp
  elif count%4==1:
    temp=a.pop()
    ans+=abs(temp-r)
    r=temp
  elif count%4==2:
    temp=a.popleft()
    ans+=abs(l-temp)
    l=temp
  elif count%4==3:
    temp=a.popleft()
    ans+=abs(r-temp)
    r=temp
  count+=1
  
l=b.pop() 
r=l
count=0
ans2=0
while len(b)>0:
  if count%4==2:
    temp=b.pop()
    ans2+=abs(temp-l)
    l=temp
  elif count%4==3:
    temp=b.pop()
    ans2+=abs(temp-r)
    r=temp
  elif count%4==0:
    temp=b.popleft()
    ans2+=abs(l-temp)
    l=temp
  elif count%4==1:
    temp=b.popleft()
    ans2+=abs(r-temp)
    r=temp
  count+=1
print(max(ans, ans2))
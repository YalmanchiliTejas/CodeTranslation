N=int(input())

alist=[]
for _ in range(N):
  a=int(input())
  alist.append(a)
alist.sort()
#print(alist)

if N%2==0:
  answer=0
  for i in range(N//2-1):
    a=alist.pop()
    answer+=2*a
  answer+=alist.pop()
  answer-=alist.pop()
  for i in range(N//2-1):
    a=alist.pop()
    answer-=2*a
    
  print(answer)
else:
  ans1=0
  alist_copy=alist[:]
  for i in range(N//2-1):
    a=alist_copy.pop()
    ans1+=2*a
  ans1+=alist_copy.pop()
  ans1+=alist_copy.pop()
  for i in range(N//2):
    a=alist_copy.pop()
    ans1-=2*a
    
  ans2=0
  alist_copy=alist[:]
  for i in range(N//2):
    a=alist_copy.pop()
    ans2+=2*a
  ans2-=alist_copy.pop()
  ans2-=alist_copy.pop()
  for i in range(N//2-1):
    a=alist_copy.pop()
    ans2-=2*a
    
  print(max(ans1,ans2))
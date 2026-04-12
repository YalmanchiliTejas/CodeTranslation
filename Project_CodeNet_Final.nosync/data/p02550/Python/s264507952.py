n,x,m=map(int,input().split())

am=[]

d={}

ch=0

for i in range(m):
  y=x%m
  
  if y==0:
    ch+=1
    break
  if y not in d:
    d[y]=0
    
    am.append(y)
    
    x=y*y
    
  else:
    stop=y
    break
    
if ch>0:
  st=0
  ans=0
  while st<=n-1 and st<=len(am)-1:
    ans+=am[st]
    st+=1
    
  print(ans)

else:
  for i in range(len(am)):
    if am[i]==y:
      now=i
      
  new_am=am[now:]
  s_new=sum(new_am)
  l=len(new_am)
  if n<i:
    print(sum(am[:n]))
    
  else:
    s=sum(am[:now])
    rest=n-now
    x=rest//l
    y=rest%l
    print(s+x*s_new+sum(new_am[:y]))
    
  
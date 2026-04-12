n,x=map(int,input().split())

sumx=[1]
pathi=[1]
for i in range(n):
  sumx+=[sumx[-1]*2+3]
  pathi+=[pathi[-1]*2+1]
  
if n==0:
  if x==1:
    print(1)
    exit()
    
elif x==1:
  print(0)
  exit()
  

elif x==sumx[-1] or x==sumx[-1]-1:
  print(pathi[-1])
  exit()
  
ans=0

for i in range(n-1,0,-1):
  x-=1
  if x>=sumx[i]:
    ans+=pathi[i]
    x-=sumx[i]
    if x>=1:
      x-=1
      ans+=1
    if x>=sumx[i]:
      ans+=pathi[i]
      x-=sumx[i]
      if x>=2:
        x-=2
        ans+=1


ans+=max(x-1,0)
print(ans)

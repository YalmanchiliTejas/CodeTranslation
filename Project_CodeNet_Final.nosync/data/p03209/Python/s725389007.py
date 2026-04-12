def calc(n,x):
  ans=0
  while 1:
    if x==1:
      break
    elif 2<=x<=lb[n-1]:
      x-=1
      n-=1
    elif x==1+lb[n-1]:
      ans+=pb[n-1]
      break
    elif x==2+lb[n-1]:
      ans+=1+pb[n-1]
      break
    elif 3+lb[n-1]<=x<=1+2*lb[n-1]:
      ans+=1+pb[n-1]
      x-=2+lb[n-1]
      n-=1
    elif x==2+2*lb[n-1]:
      ans+=1+2*pb[n-1]
      break
    elif x==3+2*lb[n-1]:
      ans+=1+2*pb[n-1]
      break
  return ans

n,x=map(int,input().split())
lb=[1]
pb=[1]
for i in range(1,51):
  lb.append(lb[i-1]*2+3)
for i in range(1,51):
  pb.append(pb[i-1]*2+1)
print(calc(n,x))
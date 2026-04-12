N,X=map(int,input().split())
Thick=[]
P=[]
a=1
b=1
for i in range(N+1):
  Thick.append(a)
  P.append(b)
  a=a*2+3
  b=b*2+1
def dfs(l,x):
  if l==0:
    return 1
  
  if x==1:
    return 0
  elif x==Thick[l]//2:
    return P[l-1]
  elif x==Thick[l]//2+1:
    return P[l-1]+1
  elif x==Thick[l]:
    return P[l-1]*2+1
  else:
    if x<Thick[l]//2:
      return dfs(l-1,x-1)
    else:
      return P[l-1]+1+dfs(l-1,x-(Thick[l]//2+1))

print(dfs(N,X))
  
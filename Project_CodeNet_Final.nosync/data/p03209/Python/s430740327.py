n,x=map(int,input().split())
plist=[1]
blist=[1]
for i in range(n):
  plist.append(plist[-1]*2+1)
  blist.append(blist[-1]*2+3)
def patty(n,x):
  if n==0:
    return 1
  else:
    if x==1:
      return 0
    elif 1<x and x<=blist[n-1]+1:
      return patty(n-1,x-1)
    elif x==blist[n-1]+2:
      return plist[n-1]+1
    elif 2+blist[n-1]<x and 2*blist[n-1]+2>=x:
      return plist[n-1]+patty(n-1,x-2-blist[n-1])+1
    else:
      return plist[n]
print(patty(n,x))

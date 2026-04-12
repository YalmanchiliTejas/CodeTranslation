import sys

n=int(input())
h=list(map(int,input().split()))
count=0
be=h[0]
maxcount=h.count(max(h))
becount=0

for i in range(n):
  if be<=h[i] and h[0]<=h[i]:
    if becount<=h[i]:
      if h[i]==max(h):
        maxcount-=1
        count+=1
        becount=h[i]
        if maxcount==0:
          print(count)
          sys.exit()
      else:
        count+=1
        becount=h[i]
    else:
      pass
  be=h[i]
  
print(count)
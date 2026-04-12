N=int(input())
H=list(map(int,input().split()))
ans=0
hh=0
for h in H:
  if h>=hh:
    ans=ans+1
    hh=h
  else:
    continue
print(ans)
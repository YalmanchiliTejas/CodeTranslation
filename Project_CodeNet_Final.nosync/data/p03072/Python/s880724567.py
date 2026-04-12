N=int(input())
H=list(map(int,input().split()))
m=H[0]
ans=1
for h in H[1:]:
  if h>=m:
    ans+=1
    m=h
print(ans)
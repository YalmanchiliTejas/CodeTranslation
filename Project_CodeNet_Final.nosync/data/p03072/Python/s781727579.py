n=int(input())
h=list(map(int,input().split()))
ans=0
tmp=h[0]
for i in h:
  if tmp<=i:
    ans+=1
    tmp=i
print(ans)
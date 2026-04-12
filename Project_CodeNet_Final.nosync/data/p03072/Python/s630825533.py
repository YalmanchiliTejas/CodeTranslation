n=int(input())
h=map(int,input().split())
m=0
ans=0
for x in h:
  if x>=m:
    m=x
    ans+=1
print(ans)
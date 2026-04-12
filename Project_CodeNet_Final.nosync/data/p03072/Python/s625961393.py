n=int(input())
h=list(map(int,input().split()))
ans=1
m=h[0]
for i in h[1:]:
  if m<=i:
    ans+=1
    m=i
print(ans)
n=int(input())
ls=[int(s) for s in input().split()]
m=0
ans=0
for i in range(n):
  if m<=ls[i]:
    ans+=1
    m=ls[i]
print(ans)
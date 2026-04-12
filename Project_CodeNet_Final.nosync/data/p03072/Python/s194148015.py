n=int(input())
l=list(map(int,input().split()))
ans=1
max=l[0]
for i in range(1,n):
  if max <=l[i]:
    max=l[i]
    ans+=1
    
print(ans)    
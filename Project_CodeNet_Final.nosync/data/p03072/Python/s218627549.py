n=int(input())
h=list(map(int,input().split()))
ma=0
ans=0
for i in range(n):
  if ma<=h[i]:
    ans+=1
    ma=h[i]
  else:
    pass
  
print(ans)
 

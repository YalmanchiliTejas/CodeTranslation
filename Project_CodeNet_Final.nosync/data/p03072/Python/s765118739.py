N=int(input())
Hi=[int(x) for x in input().split()]
ans=0
highest=0
for i in range(N):
  h=Hi[i]
  if h>=highest:
    highest=Hi[i]
    ans+=1
    
print(ans)
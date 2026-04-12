n=int(input())
L=list(map(int,input().split()))
x=0
ans=0
for i in range(n):
  if L[i]>=x:
    ans+=1
    x=L[i]
    
print(ans)
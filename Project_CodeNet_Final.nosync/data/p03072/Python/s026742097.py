n=int(input())
h=list(map(int,input().split()))
ans=1
x=h[0]
for i in range(n-1):
  if x<=h[i+1]:
    ans+=1
    x=h[i+1]
print(ans)
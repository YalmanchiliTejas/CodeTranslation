n=int(input())
h=list(map(int,input().split()))
ans=1
a=h[0]
for i in range(n-1):
  if a<=h[i+1]:
    ans+=1
    a=h[i+1]
print(ans)
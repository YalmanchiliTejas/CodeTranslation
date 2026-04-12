n=int(input())
a =list(map(int,input().split()))
ans=0
for i in range(0,n):
  if a[i]==max(a[0:i+1]):
    ans+=1
print(ans)
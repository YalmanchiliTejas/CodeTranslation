n=int(input())
l=list(map(int,input().split()))

ans=1
a=l[0]
for i in range(n-1):
  if a<=l[i+1]:
    ans+=1
    a=l[i+1]

print(ans)
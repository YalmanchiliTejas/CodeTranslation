n=int(input())
h=list(map(int,input().split()))

hi=0
ans=0
for i in range(n):
  if hi <= h[i]:
    hi = h[i]
    ans+=1
print(ans)
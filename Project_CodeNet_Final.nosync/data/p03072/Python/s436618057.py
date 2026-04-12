N=int(input())
l1=list(map(int,input().split()))
ans=0
h=0
for i in range(N):
  if h<=l1[i]:
    ans+=1
    h=max(h,l1[i])
print(ans)
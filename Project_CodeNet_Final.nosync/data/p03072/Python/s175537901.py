N=int(input())
listH=list(map(int,input().split()))
ans=0
for i in range(N):
  if max(listH[0:i+1])==listH[i]:
    ans+=1
print(ans)    
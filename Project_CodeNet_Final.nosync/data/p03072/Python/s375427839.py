N=int(input())
H=list(map(int,input().split()))

ans=0
current_max=0
for i in range(N):
  if current_max<=H[i]:
    ans+=1
  current_max=max(current_max,H[i])
print(ans)

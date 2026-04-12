N=int(input())
H=list(map(int,input().split()))
MAX=0
ans=0
for i in range(N):
  if H[i]>=MAX:
    ans+=1
    MAX=H[i]
print(ans)
N=int(input())
H=list(map(int,input().split()))
ans=1
check=H[0]
for i in range(1,N):
  if H[i]>=check:
    ans+=1
  check=max(check,H[i])
print(ans)

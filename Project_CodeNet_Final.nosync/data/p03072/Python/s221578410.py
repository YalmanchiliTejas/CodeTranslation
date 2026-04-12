n=int(input())
H=list(map(int,input().split()))

ans=1
now=H[0]
for i in range(1,n):
  if H[i]>=now:
    now=H[i]
    ans+=1
print(ans)
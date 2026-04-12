N=int(input())
H=list(map(int,input().split()))
ans=1
h=H[0]
for x in range(1,N):
  if H[x]>=h:
    ans+=1
  h=max(H[x],h)
print(ans)
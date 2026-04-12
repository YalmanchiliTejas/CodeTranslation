N=int(input())
H=list(map(int,input().split()))
maxheigh=H[0]
ans=1

for i in range(1,N):
  if H[i] >= maxheigh:
    maxheigh=H[i]
    ans+=1
    
print(ans)
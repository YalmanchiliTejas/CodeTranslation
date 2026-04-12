N = int(input())
H = list(map(int,input().split()))
M = 0
ans=0

for h in H:
  if h >= M:
    ans+=1
    M = max(M,h)
    
print(ans)
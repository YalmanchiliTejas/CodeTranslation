A,B,C,X,Y=map(int,input().split())
ans=float('inf')
for ab in range(0,200001,2):
    ans=min(ans, ab*C+A*max(0,X-ab//2)+B*max(0,Y-ab//2))
print(ans)

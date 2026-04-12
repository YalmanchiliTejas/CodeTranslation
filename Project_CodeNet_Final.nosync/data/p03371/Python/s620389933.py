A,B,C,X,Y = map(int, open(0).read().split())
ans=float('inf')
for i in range(max(X,Y) + 1):
    now=2*C*i+max(0,X-i)*A+max(0,Y-i)*B
    ans=min(ans,now)
print(ans)
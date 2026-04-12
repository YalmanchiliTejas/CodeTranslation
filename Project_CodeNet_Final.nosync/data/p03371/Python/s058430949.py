A,B,C,X,Y = map(int,input().split())
ans = 10**10
for c in range(max(X,Y)+1):
    ans = min(ans,C*2*c + A*max(0,X-c) + B*max(0,Y-c))
print(ans)
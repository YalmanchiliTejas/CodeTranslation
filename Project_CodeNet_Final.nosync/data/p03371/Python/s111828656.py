A,B,C,X,Y = map(int, input().split())

ans = A*X+B*Y
for k in range(2*max(X,Y)+1):
    ans = min(ans,2*C*k+A*max(0,X-k)+B*max(0,Y-k))

print(ans)
A, B, C, X, Y = map(int,input().split())
ans = A*X + B*Y

for k in range(X+Y+1):
    ans = min(ans,A*max(0,X-k)+B*max(0,Y-k)+2*k*C)

print(ans)

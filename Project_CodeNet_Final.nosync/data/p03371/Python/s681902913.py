A, B, C, X, Y = map(int, input().split())

ans = 10**10

ans = min(ans, A*X + B*Y, C*max(X, Y)*2)

if X <= Y:
    ans = min(ans, C*X*2 + B*(Y-X))
else:
    ans = min(ans, C*Y*2 + A*(X-Y))

print(ans)

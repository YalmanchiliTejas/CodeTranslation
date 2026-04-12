A, B, C, X, Y = map(int, input().split())

ans = 10**14

ans = min(ans, A*X+B*Y)
ans = min(ans, C*max(X, Y)*2)
if X > Y:
    ans = min(ans, C*min(X, Y)*2 + A*(X-Y))
else:
    ans = min(ans, C*min(X, Y)*2 + B*(Y-X))

print(ans)
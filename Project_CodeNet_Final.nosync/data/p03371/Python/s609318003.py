A, B, C, X, Y = list(map(int, input().split()))

ans = A*X + B*Y
c = min(X, Y)
ans = min(A*(X-c) + B*(Y-c) + c*C*2, ans)
c = max(X, Y)
ans = min(c*C*2, ans)

print(ans)
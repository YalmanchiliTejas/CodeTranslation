A, B, C, X, Y = map(int, input().split())
ans = 0

ans += min(A+B, 2*C) * min(X, Y)
X, Y = X-min(X,Y), Y-min(X,Y)
ans += min(A, 2*C) * X + min(B, 2*C) * Y

print(ans)
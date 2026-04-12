A, B, C, X, Y = map(int,input().split())
ans = A*X + B*Y
ans = min(ans, 2*C*X + B*max(0, Y-X))
ans = min(ans, 2*C*Y + A*max(0, X-Y))
print(ans)
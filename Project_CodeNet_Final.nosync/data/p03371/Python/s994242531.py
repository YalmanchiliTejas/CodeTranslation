A, B, C, X, Y = map(int, input().split())
ans = min(A*X+B*Y, max(X, Y)*2*C)
if X<=Y:
  ans = min(ans, C*2*X + B*(Y-X))
if Y<=X:
  ans = min(ans, C*2*Y + A*(X-Y))
print(ans)
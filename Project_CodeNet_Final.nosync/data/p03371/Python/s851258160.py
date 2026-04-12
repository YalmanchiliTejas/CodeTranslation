A, B, C, X, Y = map(int, input().split())
C = min(2*C, A+B)

ans = 0
ans += C*min(X, Y)
if X > Y:
  ans += min(C, A) * abs(X-Y)
else:
  ans += min(C, B) * abs(X-Y)
print(ans)

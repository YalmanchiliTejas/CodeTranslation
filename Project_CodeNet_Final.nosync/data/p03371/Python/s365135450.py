A, B, C, X, Y = map(int, input().split())
ans = 0
if A+B > 2*C:
   min_v = min(X, Y)
   ans += C * min_v * 2
   diff = abs(X - Y)
   base = A if X > Y else B
   if base * diff < C * 2 * diff:
      ans += base * diff
   else:
      ans += C * 2 * diff
else:
   print(A*X + B*Y)
   exit()
print(ans)
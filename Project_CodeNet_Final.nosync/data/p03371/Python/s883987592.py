A,B,C,X,Y = map(int,input().split())
ans = 0
if C*2 < A+B:
  ans += min(X,Y)*C*2
  if X == Y:
    pass
  elif X > Y:
    if A > C*2:
      ans += C*2*(X-Y)
    else:
      ans += A*(X-Y)
  else:
    if B > C*2:
      ans += C*2*(Y-X)
    else:
      ans += B*(Y-X)
else:
  ans = A*X + B*Y
print(ans)
      
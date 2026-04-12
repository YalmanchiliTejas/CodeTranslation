A,B,C,X,Y = map(int,input().split())

ans = 0
  
if (A + B >= C * 2):
  ans += C * 2 * min(X,Y)
  if (X > Y):
      ans += min(C * 2 * (X-Y), A * (X-Y))
  elif (X < Y):
      ans += min(C * 2 * (Y-X), B * (Y-X))
else:
  ans += A * X + B * Y
print(ans)
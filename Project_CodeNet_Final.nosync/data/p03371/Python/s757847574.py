A,B,C,X,Y = map(int,input().split())

ans = 0

if 2 * C < A + B:
  if X > Y:
    ans = min(Y * 2 * C + (X - Y) * A,C * max(X,Y) * 2)
  else:
    ans = min(X * 2 * C + (Y - X) * B,C * max(X,Y) * 2)
else:
  ans = A * X + B * Y
  
print(ans)

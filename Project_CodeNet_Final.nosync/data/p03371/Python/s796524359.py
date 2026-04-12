A, B, C, X, Y = map(int, input().split())

if (A+B) <= 2*C:
  print(A*X + B*Y)
else:
  Z = 2 * min(X, Y)
  X_rem = X - Z // 2
  Y_rem = Y - Z // 2
  
  if (X_rem != 0) and (A > 2*C):
    print(C*(2*X))
  elif (Y_rem != 0) and (B > 2*C):
    print(C*(2*Y))
  else:
    print(A*X_rem + B*Y_rem + C*Z)

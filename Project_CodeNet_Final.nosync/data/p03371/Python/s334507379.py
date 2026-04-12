A, B, C, X, Y = map(int, input().split())
min_p = 10**18
start = X*A + Y*B
if (A+B)<=2*C:
  print(A*X+B*Y)
else:
  if X <= Y:
    X, Y = Y, X
    A, B = B, A
  if A>=C*2:
    print(X*C*2)
  else:
    print(Y*C*2+(X-Y)*A)
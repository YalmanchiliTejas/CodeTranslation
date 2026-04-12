A,B,AB,X,Y=map(int,input().split())
ANS=0
if A + B >= AB * 2:
  if min(X,Y) == X:
    # X < Y
    ANS = AB * X * 2
    R = Y - X if Y - X > 0 else 0
   
    if B <= AB * 2:
      ANS += B * R
    else:
      ANS += AB * 2 * R
  else:
    # X > Y
    ANS = AB * Y * 2
    R = X - Y if X - Y > 0 else 0
    if A <= AB * 2:
      ANS += A * R
    else:
      ANS += AB * 2 * R
else:
  ANS = A * X + B * Y
print(ANS)

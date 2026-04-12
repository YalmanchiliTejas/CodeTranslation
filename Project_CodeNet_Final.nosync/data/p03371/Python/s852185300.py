A,B,C,X,Y=map(int,input().split())
if A+B > 2*C:
  cost = 2*C*min(X,Y)
  if X >= Y and A < 2*C:
      cost += A*(X-Y)
  elif X >= Y:
      cost += 2*C*(X-Y)
  elif Y >= X and B < 2*C:
      cost += B*(Y-X)
  else:
      cost += 2*C*(Y-X)
else:
  cost = A*X+B*Y
print(cost)
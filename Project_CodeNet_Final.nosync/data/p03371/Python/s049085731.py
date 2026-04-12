A,B,C,X,Y = map(int,input().split())

plan1 = (A*X) + (B*Y)
plan2 = (C*2) * max(X,Y)
plan3 = (C*2) * X + B*(Y-X)
plan4 = (C*2) * Y + A*(X-Y)

if X <= Y:
  print(min(plan1,plan2,plan3))
else:
  print(min(plan1,plan2,plan4))

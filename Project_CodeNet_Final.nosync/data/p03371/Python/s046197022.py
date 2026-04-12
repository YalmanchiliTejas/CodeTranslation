A, B, C, X, Y = map(int, input().split())
cost1 =  A+B; cost2 = C*2

if X == Y :
  print( X* min( cost1, cost2))
elif X > Y:
  a = Y * min( cost1, cost2) + ( X - Y) * A
  b = X * min( cost1, cost2)
  print( min( a, b))
else :
  a = X * min( cost1, cost2) + ( Y - X) * B
  b = Y * min( cost1, cost2)
  print( min(a,b))

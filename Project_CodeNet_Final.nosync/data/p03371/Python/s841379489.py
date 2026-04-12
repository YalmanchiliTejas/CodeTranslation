A, B, C, X, Y = map(int, input().split())
cost1 =  A+B; cost2 = C*2
 
if X == Y :
  print( X* min( cost1, cost2))
elif X> Y:
  print( min( Y* min( cost1, cost2) + (X-Y)*A , X* min( cost1, cost2)))
else :
  print( min( X* min( cost1, cost2) + (Y-X)*B , Y* min( cost1, cost2)))
A,B,C,X,Y = map(int,input().split())
if C >= A/2 + B/2:
  print(A*X+B*Y)
else:
  if X < Y:
#    add_cost_half = 2*(Y-X)*C
#    add_cost = (Y-X)*B
    ness_cost = 2*X*C
    add_cost_min = (Y-X)*min(2*C,B)
    total_cost = ness_cost + add_cost_min
    print(total_cost)
  elif X >= Y:
    ness_cost = 2*Y*C
    add_cost_min = (X-Y)*min(2*C,A)
    total_cost = ness_cost + add_cost_min
    print(total_cost)
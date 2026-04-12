

# if __name__ == "__main__":
#   A, B, C, X, Y = [int(item) for item in input().split()]
  
#   min_cost = None
#   for Na in range(0, X+1):
#     for Nb in range(0, Y+1):
#       Nc = max(X - Na, Y - Nb) * 2
      
#       cost = Na*A + Nb*B + Nc*C
#       if not min_cost:
#         min_cost = Na*A + Nb*B + Nc*C
#       else:
#         min_cost = min(cost, min_cost)
      
#   print(min_cost)
  
if __name__ == "__main__":
  A, B, C, X, Y = [int(item) for item in input().split()]

  min_cost = None
  for Nc in range(0, max(X, Y)*2+1):
    Na = max(0, X - Nc//2)
    Nb = max(0, Y - Nc//2)
    
    # print(Na, Nb, Nc)
    cost = Na*A + Nb*B + Nc*C
    if not min_cost:
      min_cost = Na*A + Nb*B + Nc*C
    else:
      min_cost = min(cost, min_cost)

  print(min_cost)

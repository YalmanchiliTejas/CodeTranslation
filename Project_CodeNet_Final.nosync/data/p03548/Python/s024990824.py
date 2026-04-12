(x, y, z) = (int(tok) for tok in input().split())
at_best = x // (y + z)

if at_best * (y + z) + z > x:
  at_best -= 1
  
print(at_best)
A, B, C, X, Y = map(int, input().split(' '))

max_c = max(2*X, 2*Y)

min_cost = float('inf')
for c in range(0, max_c+1, 2):
  a = max(0, X - c//2)
  b = max(0, Y - c//2)
  cost = A*a + B*b + C*c
  
  if cost < min_cost:
    min_cost = cost
    
    
print(min_cost)
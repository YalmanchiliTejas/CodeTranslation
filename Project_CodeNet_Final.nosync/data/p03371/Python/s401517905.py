A, B, C, X, Y = map(int, input().split())
value = float('inf')
D = max(X,Y)
for i in range(D+1):
  E = max((X-i)*A, 0)
  F = max((Y-i)*B, 0)
  valueX = 2*i*C+E+F
  if valueX < value:
    value  = valueX
print(str(value))
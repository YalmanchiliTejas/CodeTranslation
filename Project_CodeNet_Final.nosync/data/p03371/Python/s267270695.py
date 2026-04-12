import math

A, B, C, X, Y = map(int, input().split())
lowest = A*X + B*Y

for c in range(0, max(2*X, 2*Y)+1, 2):
  a = max(0, math.ceil(X-0.5*c))
  b = max(0, math.ceil(Y-0.5*c))
  if A*a + B*b + C*c < lowest:
    lowest = A*a + B*b + C*c

print(lowest)
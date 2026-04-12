import math

A, B, C, X, Y = map(int, input().split())
lowest = A*X + B*Y

for a in range(0, X+1):
  c = (X-a)*2
  if Y - 0.5*c < 0:
    b = 0
  else:
    b = math.ceil(Y - 0.5*c)
  if A*a + B*b + C*c < lowest:
    lowest = A*a + B*b + C*c
    
for b in range(0, Y+1):
  c = (Y-b)*2
  if X - 0.5*c < 0:
    a = 0
  else:
    a = math.ceil(X - 0.5*c)
  if A*a + B*b + C*c < lowest:
    lowest = A*a + B*b + C*c

print(lowest)
A,B,C,X,Y = map(int,input().split())

cost = A*X + B*Y
a = X
b = Y
c  = 0
N = max(X,Y)

for i in range(N):
  c += 2
  if a > 0:
    a -= 1
  if b > 0:
    b -= 1
  cost = min(cost,A*a + B*b + c*C)
print(cost)
A,B,C,X,Y = map(int, input().split())
if X >= Y:
  H = A*X + B*Y
  I = A*(X-Y)+C*Y*2
  J = C*X*2
else:
  H = A*X + B*Y
  I = B*(Y-X)+C*X*2
  J = C*Y*2
print(min(H,I,J))
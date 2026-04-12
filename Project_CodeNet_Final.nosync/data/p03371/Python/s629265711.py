A,B,C,X,Y = map(int,input().split())
x = 0
y = 0
pay = 0
if X == Y:
  pay = min(A*X+B*Y,2*C*X)
elif X > Y:
  pay = min(A*X+B*Y,2*C*Y+A*(X-Y),2*C*X)
else:
  pay = min(A*X+B*Y,2*C*X+B*(Y-X),2*C*Y)
print(pay)
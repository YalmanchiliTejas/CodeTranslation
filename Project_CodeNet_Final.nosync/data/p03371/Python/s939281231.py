A, B, C, X, Y = map(int, input().split())

pay = 0

XY = min([X, Y])
X -= XY
Y -= XY

if (A+B) > C*2:
    pay += XY*C*2
else:
    pay += XY*A + XY*B

if A > C*2:
    pay += X*C*2
else:
    pay += X*A

if B > C*2:
    pay += Y*C*2
else:
    pay += Y*B

print(pay)
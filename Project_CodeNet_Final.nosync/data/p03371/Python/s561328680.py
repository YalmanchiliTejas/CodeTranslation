## C - Half and Half
import math
A, B, C, X, Y = map(int, input().split())
money = []
for i in range(0, max(X,Y) + 1 ):
    val = 0
    val += A * (X - i) if X - i > 0 else 0
    val += B * (Y - i) if Y - i > 0 else 0
    money.append(  val + C * 2*i )
print(min(money))
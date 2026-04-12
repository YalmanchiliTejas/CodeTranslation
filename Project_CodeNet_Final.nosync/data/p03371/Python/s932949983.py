import math
A,B,C,X,Y = map(int,input().split())
ans = A * X + B * Y
for c in range(2 * 10 ** 5 + 1):
    a = math.ceil(X - c * 0.5)
    b = math.ceil(Y - c * 0.5)
    if a < 0:
        a = 0
    if b < 0:
        b = 0
    mny = a * A + b * B + c * C
    if mny < ans:
        ans = mny
print(ans)
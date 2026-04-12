A, B, C, X, Y = map(int, input().split())

a,b,ab = 0, 0, 0

a = X
b = Y
ab = 0

m = a * A + b * B + ab * C
big = max(X,Y)
while ab // 2 <= big:
    ab += 2
    if a > 0:
        a -= 1
    if b > 0:
        b -= 1
    m = min(m, a * A + b * B + ab * C)

print(m)
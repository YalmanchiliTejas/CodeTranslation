A, B, AB, X, Y = map(int, input().split(' '))

AV = (A + B) / 2

cost = 0

if AB <= AV:
    n = min(X, Y)
    cost += AB * n * 2
else:
    n = min(X, Y)
    cost += (A + B) * n

X -= n
Y -= n

if X > 0:
    if 2 * AB <= A:
        cost += 2 * AB * X
    else:
        cost += A * X
elif Y > 0:
    if 2 * AB <= B:
        cost += 2 * AB * Y
    else:
        cost += B * Y

print(cost)

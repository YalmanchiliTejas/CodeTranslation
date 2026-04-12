import sys
input = sys.stdin.readline

A, B, C, X, Y = map(int, input().split())

m = 10 ** 18

for i in range(max(X, Y) + 1):
    a = A * (X - i)
    b = B * (Y - i)
    c = C * i * 2

    point = 0
    for v in [a, b, c]:
        if v > 0:
            point += v

    m = min(m, point)

print(m)
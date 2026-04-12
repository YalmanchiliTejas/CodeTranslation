a, b, c, x, y = map(int, input().split())
n = [x, y, 0]
p = a * x + b * y
for i in range(max(x, y)):
    if n[0]:
        n[0] -= 1
    if n[1]:
        n[1] -= 1
    n[2] += 2
    p = min(p, a * n[0] + b * n[1] + c * n[2])
print(p)

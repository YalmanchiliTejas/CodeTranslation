a, b, c, x, y = map(int, input().split())
mini = min(x, y)

A = a*x + b*y
B = 2*c*mini + a*(x - mini) + b*(y - mini)
C = 2*c*max(x, y)

print(min(A, B, C))
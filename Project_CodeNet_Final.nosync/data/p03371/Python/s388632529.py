# Code for C - Half and Half
# Use input() to fetch data from STDIN
[a, b, c, x, y] = [int(x) for x in input().split()]

p = max(x, y) * c * 2
m = min(x, y)
q = m * c * 2 + (x - m) * a + (y - m) * b
r = a * x + b * y

print(min(p, q, r))

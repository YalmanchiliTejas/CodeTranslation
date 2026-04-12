# Code for C - Half and Half
# Use input() to fetch data from STDIN
[a, b, c, x, y] = [int(x) for x in input().split()]

s = []
for i in range(0, 10 ** 5 + 1):
    s.append(i * c * 2 + max(x - i, 0) * a + max(y - i, 0) * b)

print(min(s))

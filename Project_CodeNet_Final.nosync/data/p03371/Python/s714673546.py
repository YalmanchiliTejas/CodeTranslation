import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

a, b, c, x, y = map(int, readline().split())

p1 = a * x + b * y
if y >= x:
    p2 = c * x * 2 + b * (y - x)
else:
    p2 = a * (x - y) + c * y * 2
p3 = c * max(x, y) * 2

print(min(p1,p2,p3))
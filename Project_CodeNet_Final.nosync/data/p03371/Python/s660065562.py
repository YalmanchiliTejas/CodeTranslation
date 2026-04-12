import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

a, b, c, x, y = map(int, input().split())

if 2 * c >= a + b:
    print(a * x + b * y)
    sys.exit(0)

ans = 0
_min = min(x, y)
ans += (2 * c) * _min
x -= _min
y -= _min
if x != 0:
    ans += x * min(a, 2 * c)
    pass
if y != 0:
    ans += y * min(b, 2 * c)
print(ans)

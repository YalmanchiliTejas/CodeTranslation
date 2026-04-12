import sys
raw_input = sys.stdin.readline
range = xrange
a, b, c, x, y = map(int, raw_input().split())
if 2 * c >= a + b :
    print x * a + y * b
else:
    DP = [0]*(max(x, y)+1)
    for i in range(max(x, y)+1):
        DP[i] = 2 * c * i + a * max(0, x-i) + b * max(0, y-i)
    print min(DP)
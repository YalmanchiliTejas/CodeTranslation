import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

a, b, c, x, y = map(int, readline().split())

total = 0

#
if a + b >= 2*c:    # ABを買う場合
    if (max(x, y) == x and 2*c < a) or (max(x, y) == y and 2*c < b):    # ABのみを買う場合
        total = max(x, y) * 2*c
    else:
        # 足りない方を買い足す場合
        if min(x, y) == x:
            total = x * 2 * c + (y - x) * b
        else:
            total = y * 2 * c + (x - y) * a
else:               # ABを買わない場合
    total = a*x + b*y

print(total)

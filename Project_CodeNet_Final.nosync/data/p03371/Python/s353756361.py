import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

A, B, C, X, Y = map(int, read().split())

cnt_A = max(X, Y)
cnt_B = max(X, Y)

ans = 10**9 + 1

for i in range(int(1e5 + 1)):
    acc = i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B
    ans = min(ans, acc)

print(ans)
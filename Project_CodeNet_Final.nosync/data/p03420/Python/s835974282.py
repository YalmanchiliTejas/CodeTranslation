import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n, k = map(int, readline().split())
ans = 0
for i in range(k + 1, n + 1):
    cnt = 0
    max_x = n // i
    cnt += max_x * (i - k)
    low = max_x * i + k
    if low <= n:
        high = min((max_x + 1) * i - 1, n)
        cnt += high - low + 1
    ans += cnt
if k == 0:
    ans -= n
print(ans)

from collections import Counter
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n = int(readline())
c = Counter(readline().decode().rstrip())
for i in range(1, n):
    c2 = Counter(readline().decode().rstrip())
    for k, v in c.items():
        c[k] = min(c[k], c2[k])
l = sorted(c.items())
ans = ''
for k, v in l:
    ans += k * v
print(ans)
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

x, y, z = map(int, readline().split())
q = x // (y + z)
r = x % (y + z)
ans = q if z <= r else q - 1
print(ans)
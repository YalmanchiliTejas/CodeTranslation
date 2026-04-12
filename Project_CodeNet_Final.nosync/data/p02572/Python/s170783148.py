import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n, *a = map(int, read().split())

MOD = 10 ** 9 + 7
total = 0
s = sum(a)

for i in range(n):
    total += a[i] * (s - a[i])

print((total // 2) % MOD)

import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n, m = map(int, readline().split())
#arr = [line.split() for line in readlines()]

if n == m:
    print("Yes")
else:
    print("No")
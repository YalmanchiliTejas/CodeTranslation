import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

N, M = map(int, read().split())

if N == M:
    print("Yes")
else:
    print("No")

import sys
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
read = sys.stdin.buffer.read
sys.setrecursionlimit(10 ** 7)

N, M = map(int, readline().split())
if N == M:
    print('Yes')
else:
    print('No')
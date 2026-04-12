import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N, M = map(int, readline().split())
if N == M:
    print('Yes')
else:
    print('No')
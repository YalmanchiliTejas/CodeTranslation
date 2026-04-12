import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

s = list(input())
if len(set(s)) == 1:
    print('No')
else:
    print('Yes')

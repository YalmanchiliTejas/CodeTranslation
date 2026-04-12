import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

from bisect import bisect_left, bisect_right

n = int(readline())
a = [int(readline()) for _ in range(n)]
inf = float('inf')
memo = [inf] * n
for aa in a[::-1]:
    memo[bisect_right(memo, aa)] = aa
print(bisect_left(memo, inf))

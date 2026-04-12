import sys
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mod = 10**9 + 7

N, M = rl()

if N == M:
    print('Yes')
else:
    print('No')
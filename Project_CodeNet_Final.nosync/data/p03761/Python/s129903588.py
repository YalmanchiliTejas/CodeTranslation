
import sys
input = sys.stdin.readline
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
# A = [ int(input()) for _ in range(N) ]
##############################

N = int(input())
S = [ input() for _ in range(N) ]

ans = []

for i in range(ord('a'), ord('z')+1):
    x = INF
    for c in S:
        x = min(x, c.count(chr(i)))

    if x > 0:
        ans.append(chr(i)*x)

print(''.join(ans))


import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

A, B, C, X, Y = map(int, input().split())

ans = 0
if X >= Y:
    ans = min(A*X+B*Y, C*(Y)*2+A*(X-Y))
else:
    ans = min(A*X+B*Y, C*(X)*2+B*(Y-X))


ans = min(ans, C*max(X, Y)*2)
print(ans)

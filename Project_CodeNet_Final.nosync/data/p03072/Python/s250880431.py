import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n = int(input())
h = list(map(int, input().split()))

ans = 0
ma = h[0]
for i in h:
    if ma <= i:
        ans += 1
    ma = max(ma, i)

print(ans)

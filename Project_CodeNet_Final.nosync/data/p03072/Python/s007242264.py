# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
H = list(map(int, input().split()))
ans = 1
maxH = H[0]
for h in H[1:]:
    if h >= maxH:
        ans += 1
        maxH = h
print(ans)

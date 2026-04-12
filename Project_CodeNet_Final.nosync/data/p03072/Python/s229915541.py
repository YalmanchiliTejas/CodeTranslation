import sys
input = sys.stdin.readline
N = int(input())
H = [int(x) for x in input().split()]

ans = 0
maxH = 0
for i in range(N) :
    if H[i] >= maxH :
        ans += 1
    maxH = max(maxH, H[i])

print(ans)

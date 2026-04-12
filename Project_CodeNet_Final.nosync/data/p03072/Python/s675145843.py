N = int(input())
H = list(map(int, input().split()))
ans = 0
maxH = 0
for i in range(N):
    if H[i] >= maxH:
        ans += 1
    maxH = max(maxH, H[i])

print (ans)
n = int(input())
H = list(map(int, input().split()))
ans = 1
maxH = H[0]

for i in range(1, n):
    if maxH <= H[i]:
        ans += 1
    maxH = max(maxH, H[i])
print(ans)
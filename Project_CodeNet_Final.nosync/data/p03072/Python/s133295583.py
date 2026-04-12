n = int(input())
H = list(map(int, input().split()))

maxh = 0
cumH = [0]
for i in range(n):
    maxh = max(maxh, H[i])
    cumH.append(maxh)

ans = 0
for i in range(n):
    if H[i] >= cumH[i]:
        ans += 1
print(ans)

N = int(input())
H = list(map(int, input().split()))

maxv = H[0]
ans = 1
for i in range(1, N):
    if H[i] >= maxv:
        ans += 1
    maxv = max(maxv, H[i])

print(ans)

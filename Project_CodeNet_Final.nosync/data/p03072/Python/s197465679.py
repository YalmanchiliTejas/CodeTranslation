N = int(input())
H = list(map(int, input().split()))

ans = 0
tmp = H[0]
for i in range(N):
    if tmp <= H[i]:
        ans += 1
        tmp = max(tmp, H[i])

print(ans)

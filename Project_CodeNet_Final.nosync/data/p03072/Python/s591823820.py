N = int(input())
H = list(map(int, input().split()))

ans = 1
m = H[0]
for i in range(1, N):
    if m <= H[i]:
        ans += 1
        m = H[i]

print(ans)

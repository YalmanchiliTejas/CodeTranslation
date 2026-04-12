N = int(input())
H = list(map(int, input().split()))

ans = 1
M = H[0]
for i in range(1, N):
    if M <= H[i]:
        ans += 1
        M = H[i]

print(ans)

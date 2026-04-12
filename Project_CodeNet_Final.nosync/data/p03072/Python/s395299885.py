N = int(input())
H = list(map(int, input().split()))
ans = 0
M = 0
for i in range(N):
    if M <= H[i]:
        ans += 1
        M = H[i]

print(ans)
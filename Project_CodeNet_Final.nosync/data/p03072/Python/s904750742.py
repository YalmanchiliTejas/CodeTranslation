N = int(input())
H = list(map(int,input().split()))
M = H[0]
ans = 0
for i in range(N):
    if M <= H[i]:
        M = H[i]
        ans += 1
print(ans)
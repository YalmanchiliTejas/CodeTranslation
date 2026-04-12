N = int(input())
H = list(map(int, input().split()))

ans = 0
c = 0
for i in range(N):
    c = max(H[i], c)
    if c <= H[i]:
        ans += 1
print(ans)
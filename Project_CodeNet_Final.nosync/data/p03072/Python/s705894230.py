n = int(input())
H = list(map(int, input().split()))
ans = 1
for i in range(1, n):
    maxh = max(H[0:i])
    if maxh <= H[i]:
        ans += 1
print(ans)